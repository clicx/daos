/**
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * GOVERNMENT LICENSE RIGHTS-OPEN SOURCE SOFTWARE
 * The Government's rights to use, modify, reproduce, release, perform, display,
 * or disclose this software are subject to the terms of the LGPL License as
 * provided in Contract No. B609815.
 * Any reproduction of computer software, computer software documentation, or
 * portions thereof marked with this legend must also reproduce the markings.
 *
 * (C) Copyright 2016 Intel Corporation.
 */
/**
 * This file is part of dsm
 *
 * dsm/tests/io.c
 */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <daos_mgmt.h>
#include <daos_m.h>
#include <daos_event.h>

#define UPDATE_CSUM_SIZE	32

typedef struct {
	daos_rank_t		ranks[8];
	daos_rank_list_t	svc;
	uuid_t			uuid;
	uuid_t			co_uuid;
	daos_handle_t		eq;
	daos_handle_t		poh;
	daos_handle_t		coh;
	bool			async;
} test_arg_t;

struct ioreq {
	daos_handle_t	 oh;

	test_arg_t	*arg;

	daos_event_t	 ev;

	daos_dkey_t	 dkey;

	daos_iov_t	 val_iov;

	daos_csum_buf_t	 csum;
	char		 csum_buf[UPDATE_CSUM_SIZE];

	daos_vec_iod_t	 vio;
	daos_recx_t	 rex;
	daos_epoch_range_t erange;

	daos_sg_list_t	 sgl;
};

static void
ioreq_init(struct ioreq *req, daos_unit_oid_t oid, test_arg_t *arg)
{
	int rc;

	memset(req, 0, sizeof(*req));

	req->arg = arg;
	if (arg->async) {
		rc = daos_event_init(&req->ev, arg->eq, NULL);
		assert_int_equal(rc, 0);
	}

	/** sgl */
	req->sgl.sg_nr.num = 1;
	req->sgl.sg_iovs = &req->val_iov;

	/** csum */
	daos_csum_set(&req->csum, &req->csum_buf[0], UPDATE_CSUM_SIZE);

	/** record extent */
	req->rex.rx_nr		= 1;
	req->rex.rx_idx		= 0;

	/** epoch range: required by the wire format */
	req->erange.epr_lo = 0;
	req->erange.epr_hi = DAOS_EPOCH_MAX;

	/** vector I/O descriptor */
	req->vio.vd_recxs	= &req->rex;
	req->vio.vd_csums	= &req->csum;
	req->vio.vd_nr		= 1;
	req->vio.vd_eprs	= &req->erange;

	/** open the object */
	rc = dsm_obj_open(arg->coh, oid, 0, &req->oh, NULL);
	assert_int_equal(rc, 0);
}

static void
ioreq_fini(struct ioreq *req)
{
	int rc;

	rc = dsm_obj_close(req->oh, NULL);
	assert_int_equal(rc, 0);

	if (req->arg->async) {
		rc = daos_event_fini(&req->ev);
		assert_int_equal(rc, 0);
	}
}

static void
insert(const char *dkey, const char *akey, uint64_t idx, void *val,
       daos_size_t size, daos_epoch_t epoch, struct ioreq *req)
{
	int		 rc;

	/** dkey */
	daos_iov_set(&req->dkey, (void *)dkey, strlen(dkey));

	/** akey */
	daos_iov_set(&req->vio.vd_name, (void *)akey, strlen(akey));

	/** val */
	daos_iov_set(&req->val_iov, val, size);

	/** record extent */
	req->rex.rx_rsize = size;
	req->rex.rx_idx = idx;

	/** XXX: to be fixed */
	req->erange.epr_lo = epoch;

	/** execute update operation */
	rc = dsm_obj_update(req->oh, epoch, &req->dkey, 1, &req->vio, &req->sgl,
			    req->arg->async ? &req->ev : NULL);
	assert_int_equal(rc, 0);

	if (req->arg->async) {
		daos_event_t	*evp;

		/** wait for update completion */
		rc = daos_eq_poll(req->arg->eq, 1, DAOS_EQ_WAIT, 1, &evp);
		assert_int_equal(rc, 1);
		assert_ptr_equal(evp, &req->ev);
		assert_int_equal(evp->ev_error, 0);
	}
}

static void
lookup(const char *dkey, const char *akey, uint64_t idx, void *val,
       daos_size_t size, daos_epoch_t epoch, struct ioreq *req)
{
	int rc;

	/** dkey */
	daos_iov_set(&req->dkey, (void *)dkey, strlen(dkey));

	/** akey */
	daos_iov_set(&req->vio.vd_name, (void *)akey, strlen(akey));

	/** val */
	daos_iov_set(&req->val_iov, val, size);

	/** record extent */
	req->rex.rx_rsize = size;
	req->rex.rx_idx = idx;

	/** XXX: to be fixed */
	req->erange.epr_lo = epoch;

	/** execute fetch operation */
	rc = dsm_obj_fetch(req->oh, epoch, &req->dkey, 1, &req->vio, &req->sgl,
			   NULL, req->arg->async ? &req->ev : NULL);
	assert_int_equal(rc, 0);

	if (req->arg->async) {
		daos_event_t	*evp;

		/** wait for fetch completion */
		rc = daos_eq_poll(req->arg->eq, 1, DAOS_EQ_WAIT, 1, &evp);
		assert_int_equal(rc, 1);
		assert_ptr_equal(evp, &req->ev);
		assert_int_equal(evp->ev_error, 0);
	}
}

static inline void
obj_random(daos_unit_oid_t *oid)
{
	/** choose random object */
	oid->id_pub.lo = rand();
	oid->id_pub.mid = rand();
	oid->id_pub.hi = rand();
	oid->id_shard = 0;
	oid->id_pad_32 = rand() % 16; /** must be nr target in the future */
}

/** i/o to variable idx offset */
static void
io_var_idx_offset(void **state)
{
	daos_unit_oid_t	 oid;
	struct ioreq	 req;
	daos_off_t	 offset;

	/** choose random object */
	obj_random(&oid);

	ioreq_init(&req, oid, (test_arg_t *)*state);

	for (offset = UINT64_MAX; offset > 0; offset >>= 8) {
		char buf[10];

		print_message("idx offset: %lu\n", offset);

		/** Insert */
		insert("var_idx_off_d", "var_idx_off_a", offset, "data",
		       strlen("data") + 1, 0, &req);

		/** Lookup */
		memset(buf, 0, 10);
		lookup("var_idx_off_d", "var_idx_off_a", offset, buf, 10, 0, &req);
		/** XXX assert disabled until DAOS-95 is fixed  */
		/* assert_int_equal(req.rex.rx_rsize, strlen(data) + 1); */

		/** Verify data consistency */
		assert_string_equal(buf, "data");
	}

	ioreq_fini(&req);

}

/** i/o to variable akey size */
static void
io_var_akey_size(void **state)
{
	daos_unit_oid_t	 oid;
	struct ioreq	 req;
	daos_size_t	 size;
	const int	 max_size = 1 << 10;
	char		*key;

	/** akey not supported yet */
	skip();

	/** choose random object */
	obj_random(&oid);

	ioreq_init(&req, oid, (test_arg_t *)*state);

	key = malloc(max_size);
	assert_non_null(key);
	memset(key, 'a', max_size);

	for (size = 1; size <= max_size; size <<= 1) {
		char buf[10];

		print_message("akey size: %lu\n", size);

		/** Insert */
		key[size] = '\0';
		insert("var_akey_size_d", key, 0, "data", strlen("data") + 1, 0,
		       &req);

		/** Lookup */
		memset(buf, 0, 10);
		lookup("var_dkey_size_d", key, 0, buf, 10, 0, &req);
		/** XXX assert disabled until DAOS-95 is fixed  */
		/* assert_int_equal(req.rex.rx_rsize, strlen(data) + 1); */

		/** Verify data consistency */
		assert_string_equal(buf, "data");
		key[size] = 'b';
	}

	free(key);
	ioreq_fini(&req);
}

/** i/o to variable dkey size */
static void
io_var_dkey_size(void **state)
{
	daos_unit_oid_t	 oid;
	struct ioreq	 req;
	daos_size_t	 size;
	const int	 max_size = 1 << 10;
	char		*key;

	/** choose random object */
	obj_random(&oid);

	ioreq_init(&req, oid, (test_arg_t *)*state);

	key = malloc(max_size);
	assert_non_null(key);
	memset(key, 'a', max_size);

	for (size = 1; size <= max_size; size <<= 1) {
		char buf[10];

		print_message("dkey size: %lu\n", size);

		/** Insert */
		key[size] = '\0';
		insert(key, "var_dkey_size_a", 0, "data", strlen("data") + 1, 0,
		       &req);

		/** Lookup */
		memset(buf, 0, 10);
		lookup(key, "var_dkey_size_a", 0, buf, 10, 0, &req);
		/** XXX assert disabled until DAOS-95 is fixed  */
		/* assert_int_equal(req.rex.rx_rsize, strlen(data) + 1); */

		/** Verify data consistency */
		assert_string_equal(buf, "data");
		key[size] = 'b';
	}

	free(key);
	ioreq_fini(&req);
}

/** i/o to variable aligned record size */
static void
io_var_rec_size(void **state)
{
	daos_unit_oid_t	 oid;
	daos_epoch_t	 epoch;
	struct ioreq	 req;
	daos_size_t	 size;
	const int	 max_size = 1 << 20;
	char		*fetch_buf;
	char		*update_buf;

	/** choose random object */
	obj_random(&oid);

	/** random epoch as well */
	epoch = rand();

	ioreq_init(&req, oid, (test_arg_t *)*state);

	fetch_buf = malloc(max_size);
	assert_non_null(fetch_buf);

	update_buf = malloc(max_size);
	assert_non_null(update_buf);
	memset(update_buf, (rand() % 94) + 33, max_size);

	for (size = 1; size <= max_size; size <<= 1, epoch++) {
		print_message("Record size: %lu val: \'%c\' epoch: %lu\n",
			      size, update_buf[0], epoch);

		/** Insert */
		insert("var_rec_size_d", "var_rec_size_a", 0, update_buf,
		       size, epoch, &req);

		/** Lookup */
		memset(fetch_buf, 0, max_size);
		lookup("var_rec_size_d", "var_rec_size_a", 0, fetch_buf,
		       max_size, epoch, &req);
		/** XXX assert disabled until DAOS-95 is fixed  */
		/* assert_int_equal(req.rex.rx_rsize, size); */

		/** Verify data consistency */
		assert_memory_equal(update_buf, fetch_buf, size);
	}

	free(update_buf);
	free(fetch_buf);
	ioreq_fini(&req);
}

/** very basic update/fetch with data verification */
static void
io_simple(void **state)
{
	daos_unit_oid_t	 oid;
	struct ioreq	 req;
	const char	 dkey[] = "test_update dkey";
	const char	 akey[] = "test_update akey";
	const char	 rec[]  = "test_update record";
	char		*buf;

	obj_random(&oid);

	ioreq_init(&req, oid, (test_arg_t *)*state);

	/** Insert */
	print_message("Insert(e=0)/lookup(e=0)/verify simple kv record\n");

	insert(dkey, akey, 0, (void *)rec, strlen(rec), 0, &req);

	/** Lookup */
	buf = calloc(64, 1);
	assert_non_null(buf);
	lookup(dkey, akey, 0, buf, 64, 0, &req);

	/** Verify data consistency */
	print_message("size = %lu\n", req.rex.rx_rsize);
	/** XXX assert disabled until DAOS-95 is fixed  */
	/* assert_int_equal(req.rex.rx_rsize, strlen(rec)); */
	assert_memory_equal(buf, rec, strlen(rec));
	free(buf);
	ioreq_fini(&req);
}

static int
async_enable(void **state)
{
	test_arg_t	*arg = *state;

	arg->async = true;
	return 0;
}

static int
async_disable(void **state)
{
	test_arg_t	*arg = *state;

	arg->async = false;
	return 0;
}

static const struct CMUnitTest io_tests[] = {
	{ "DSM200: simple update/fetch/verify",
	  io_simple, async_disable, NULL},
	{ "DSM201: simple update/fetch/verify (async)",
	  io_simple, async_enable, NULL},
	{ "DSM202: i/o with variable rec size",
	  io_var_rec_size, async_disable, NULL},
	{ "DSM203: i/o with variable rec size(async)",
	  io_var_rec_size, async_enable, NULL},
	{ "DSM204: i/o with variable dkey size",
	  io_var_dkey_size, async_enable, NULL},
	{ "DSM205: i/o with variable akey size",
	  io_var_akey_size, async_disable, NULL},
	{ "DSM206: i/o with variable index",
	  io_var_idx_offset, async_enable, NULL},
};

static int
setup(void **state)
{
	test_arg_t	*arg;
	int		 rc;

	arg = malloc(sizeof(test_arg_t));
	if (arg == NULL)
		return -1;

	rc = daos_eq_create(&arg->eq);
	if (rc)
		return rc;

	arg->svc.rl_nr.num = 8;
	arg->svc.rl_nr.num_out = 0;
	arg->svc.rl_ranks = arg->ranks;

	/** create pool with minimal size */
	rc = dmg_pool_create(0, geteuid(), getegid(), "srv_grp", NULL, "pmem",
			     0, &arg->svc, arg->uuid, NULL);
	if (rc)
		return rc;

	/** connect to pool */
	rc = dsm_pool_connect(arg->uuid, NULL /* grp */, &arg->svc,
			      DAOS_PC_RW, NULL /* failed */, &arg->poh,
			      NULL /* ev */);
	if (rc)
		return rc;

	/** create container */
	uuid_generate(arg->co_uuid);
	rc = dsm_co_create(arg->poh, arg->co_uuid, NULL);
	if (rc)
		return rc;

	/** open container */
	rc = dsm_co_open(arg->poh, arg->co_uuid, DAOS_COO_RW, NULL, &arg->coh,
			 NULL, NULL);
	if (rc)
		return rc;

	*state = arg;
	return 0;
}

static int
teardown(void **state) {
	test_arg_t	*arg = *state;
	int		 rc;

	rc = dsm_co_close(arg->coh, NULL);
	if (rc)
		return rc;

	rc = dsm_co_destroy(arg->poh, arg->co_uuid, 1, NULL);
	if (rc)
		return rc;

	rc = dsm_pool_disconnect(arg->poh, NULL /* ev */);
	if (rc)
		return rc;

	rc = dmg_pool_destroy(arg->uuid, "srv_grp", 1, NULL);
	if (rc)
		return rc;

	rc = daos_eq_destroy(arg->eq, 0);
	if (rc)
		return rc;

	free(arg);
	return 0;
}

int
run_io_test(void)
{
	return cmocka_run_group_tests_name("DSM io tests", io_tests,
					   setup, teardown);
}

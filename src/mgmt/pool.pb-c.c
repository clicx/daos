/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: pool.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "pool.pb-c.h"
void   mgmt__pool_create_req__init
                     (Mgmt__PoolCreateReq         *message)
{
  static const Mgmt__PoolCreateReq init_value = MGMT__POOL_CREATE_REQ__INIT;
  *message = init_value;
}
size_t mgmt__pool_create_req__get_packed_size
                     (const Mgmt__PoolCreateReq *message)
{
  assert(message->base.descriptor == &mgmt__pool_create_req__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__pool_create_req__pack
                     (const Mgmt__PoolCreateReq *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__pool_create_req__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__pool_create_req__pack_to_buffer
                     (const Mgmt__PoolCreateReq *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__pool_create_req__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__PoolCreateReq *
       mgmt__pool_create_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__PoolCreateReq *)
     protobuf_c_message_unpack (&mgmt__pool_create_req__descriptor,
                                allocator, len, data);
}
void   mgmt__pool_create_req__free_unpacked
                     (Mgmt__PoolCreateReq *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__pool_create_req__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__pool_create_resp__init
                     (Mgmt__PoolCreateResp         *message)
{
  static const Mgmt__PoolCreateResp init_value = MGMT__POOL_CREATE_RESP__INIT;
  *message = init_value;
}
size_t mgmt__pool_create_resp__get_packed_size
                     (const Mgmt__PoolCreateResp *message)
{
  assert(message->base.descriptor == &mgmt__pool_create_resp__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__pool_create_resp__pack
                     (const Mgmt__PoolCreateResp *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__pool_create_resp__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__pool_create_resp__pack_to_buffer
                     (const Mgmt__PoolCreateResp *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__pool_create_resp__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__PoolCreateResp *
       mgmt__pool_create_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__PoolCreateResp *)
     protobuf_c_message_unpack (&mgmt__pool_create_resp__descriptor,
                                allocator, len, data);
}
void   mgmt__pool_create_resp__free_unpacked
                     (Mgmt__PoolCreateResp *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__pool_create_resp__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__pool_destroy_req__init
                     (Mgmt__PoolDestroyReq         *message)
{
  static const Mgmt__PoolDestroyReq init_value = MGMT__POOL_DESTROY_REQ__INIT;
  *message = init_value;
}
size_t mgmt__pool_destroy_req__get_packed_size
                     (const Mgmt__PoolDestroyReq *message)
{
  assert(message->base.descriptor == &mgmt__pool_destroy_req__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__pool_destroy_req__pack
                     (const Mgmt__PoolDestroyReq *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__pool_destroy_req__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__pool_destroy_req__pack_to_buffer
                     (const Mgmt__PoolDestroyReq *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__pool_destroy_req__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__PoolDestroyReq *
       mgmt__pool_destroy_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__PoolDestroyReq *)
     protobuf_c_message_unpack (&mgmt__pool_destroy_req__descriptor,
                                allocator, len, data);
}
void   mgmt__pool_destroy_req__free_unpacked
                     (Mgmt__PoolDestroyReq *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__pool_destroy_req__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__pool_destroy_resp__init
                     (Mgmt__PoolDestroyResp         *message)
{
  static const Mgmt__PoolDestroyResp init_value = MGMT__POOL_DESTROY_RESP__INIT;
  *message = init_value;
}
size_t mgmt__pool_destroy_resp__get_packed_size
                     (const Mgmt__PoolDestroyResp *message)
{
  assert(message->base.descriptor == &mgmt__pool_destroy_resp__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__pool_destroy_resp__pack
                     (const Mgmt__PoolDestroyResp *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__pool_destroy_resp__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__pool_destroy_resp__pack_to_buffer
                     (const Mgmt__PoolDestroyResp *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__pool_destroy_resp__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__PoolDestroyResp *
       mgmt__pool_destroy_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__PoolDestroyResp *)
     protobuf_c_message_unpack (&mgmt__pool_destroy_resp__descriptor,
                                allocator, len, data);
}
void   mgmt__pool_destroy_resp__free_unpacked
                     (Mgmt__PoolDestroyResp *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__pool_destroy_resp__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__list_pools_req__init
                     (Mgmt__ListPoolsReq         *message)
{
  static const Mgmt__ListPoolsReq init_value = MGMT__LIST_POOLS_REQ__INIT;
  *message = init_value;
}
size_t mgmt__list_pools_req__get_packed_size
                     (const Mgmt__ListPoolsReq *message)
{
  assert(message->base.descriptor == &mgmt__list_pools_req__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__list_pools_req__pack
                     (const Mgmt__ListPoolsReq *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__list_pools_req__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__list_pools_req__pack_to_buffer
                     (const Mgmt__ListPoolsReq *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__list_pools_req__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__ListPoolsReq *
       mgmt__list_pools_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__ListPoolsReq *)
     protobuf_c_message_unpack (&mgmt__list_pools_req__descriptor,
                                allocator, len, data);
}
void   mgmt__list_pools_req__free_unpacked
                     (Mgmt__ListPoolsReq *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__list_pools_req__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__list_pools_resp__pool__init
                     (Mgmt__ListPoolsResp__Pool         *message)
{
  static const Mgmt__ListPoolsResp__Pool init_value = MGMT__LIST_POOLS_RESP__POOL__INIT;
  *message = init_value;
}
void   mgmt__list_pools_resp__init
                     (Mgmt__ListPoolsResp         *message)
{
  static const Mgmt__ListPoolsResp init_value = MGMT__LIST_POOLS_RESP__INIT;
  *message = init_value;
}
size_t mgmt__list_pools_resp__get_packed_size
                     (const Mgmt__ListPoolsResp *message)
{
  assert(message->base.descriptor == &mgmt__list_pools_resp__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__list_pools_resp__pack
                     (const Mgmt__ListPoolsResp *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__list_pools_resp__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__list_pools_resp__pack_to_buffer
                     (const Mgmt__ListPoolsResp *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__list_pools_resp__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__ListPoolsResp *
       mgmt__list_pools_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__ListPoolsResp *)
     protobuf_c_message_unpack (&mgmt__list_pools_resp__descriptor,
                                allocator, len, data);
}
void   mgmt__list_pools_resp__free_unpacked
                     (Mgmt__ListPoolsResp *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__list_pools_resp__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__list_cont_req__init
                     (Mgmt__ListContReq         *message)
{
  static const Mgmt__ListContReq init_value = MGMT__LIST_CONT_REQ__INIT;
  *message = init_value;
}
size_t mgmt__list_cont_req__get_packed_size
                     (const Mgmt__ListContReq *message)
{
  assert(message->base.descriptor == &mgmt__list_cont_req__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__list_cont_req__pack
                     (const Mgmt__ListContReq *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__list_cont_req__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__list_cont_req__pack_to_buffer
                     (const Mgmt__ListContReq *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__list_cont_req__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__ListContReq *
       mgmt__list_cont_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__ListContReq *)
     protobuf_c_message_unpack (&mgmt__list_cont_req__descriptor,
                                allocator, len, data);
}
void   mgmt__list_cont_req__free_unpacked
                     (Mgmt__ListContReq *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__list_cont_req__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__list_cont_resp__cont__init
                     (Mgmt__ListContResp__Cont         *message)
{
  static const Mgmt__ListContResp__Cont init_value = MGMT__LIST_CONT_RESP__CONT__INIT;
  *message = init_value;
}
void   mgmt__list_cont_resp__init
                     (Mgmt__ListContResp         *message)
{
  static const Mgmt__ListContResp init_value = MGMT__LIST_CONT_RESP__INIT;
  *message = init_value;
}
size_t mgmt__list_cont_resp__get_packed_size
                     (const Mgmt__ListContResp *message)
{
  assert(message->base.descriptor == &mgmt__list_cont_resp__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__list_cont_resp__pack
                     (const Mgmt__ListContResp *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__list_cont_resp__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__list_cont_resp__pack_to_buffer
                     (const Mgmt__ListContResp *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__list_cont_resp__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__ListContResp *
       mgmt__list_cont_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__ListContResp *)
     protobuf_c_message_unpack (&mgmt__list_cont_resp__descriptor,
                                allocator, len, data);
}
void   mgmt__list_cont_resp__free_unpacked
                     (Mgmt__ListContResp *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__list_cont_resp__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__pool_set_prop_req__init
                     (Mgmt__PoolSetPropReq         *message)
{
  static const Mgmt__PoolSetPropReq init_value = MGMT__POOL_SET_PROP_REQ__INIT;
  *message = init_value;
}
size_t mgmt__pool_set_prop_req__get_packed_size
                     (const Mgmt__PoolSetPropReq *message)
{
  assert(message->base.descriptor == &mgmt__pool_set_prop_req__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__pool_set_prop_req__pack
                     (const Mgmt__PoolSetPropReq *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__pool_set_prop_req__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__pool_set_prop_req__pack_to_buffer
                     (const Mgmt__PoolSetPropReq *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__pool_set_prop_req__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__PoolSetPropReq *
       mgmt__pool_set_prop_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__PoolSetPropReq *)
     protobuf_c_message_unpack (&mgmt__pool_set_prop_req__descriptor,
                                allocator, len, data);
}
void   mgmt__pool_set_prop_req__free_unpacked
                     (Mgmt__PoolSetPropReq *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__pool_set_prop_req__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__pool_set_prop_resp__init
                     (Mgmt__PoolSetPropResp         *message)
{
  static const Mgmt__PoolSetPropResp init_value = MGMT__POOL_SET_PROP_RESP__INIT;
  *message = init_value;
}
size_t mgmt__pool_set_prop_resp__get_packed_size
                     (const Mgmt__PoolSetPropResp *message)
{
  assert(message->base.descriptor == &mgmt__pool_set_prop_resp__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__pool_set_prop_resp__pack
                     (const Mgmt__PoolSetPropResp *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__pool_set_prop_resp__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__pool_set_prop_resp__pack_to_buffer
                     (const Mgmt__PoolSetPropResp *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__pool_set_prop_resp__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__PoolSetPropResp *
       mgmt__pool_set_prop_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__PoolSetPropResp *)
     protobuf_c_message_unpack (&mgmt__pool_set_prop_resp__descriptor,
                                allocator, len, data);
}
void   mgmt__pool_set_prop_resp__free_unpacked
                     (Mgmt__PoolSetPropResp *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__pool_set_prop_resp__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor mgmt__pool_create_req__field_descriptors[9] =
{
  {
    "scmbytes",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolCreateReq, scmbytes),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "nvmebytes",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolCreateReq, nvmebytes),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "ranks",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Mgmt__PoolCreateReq, n_ranks),
    offsetof(Mgmt__PoolCreateReq, ranks),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "numsvcreps",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolCreateReq, numsvcreps),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "user",
    5,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolCreateReq, user),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "usergroup",
    6,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolCreateReq, usergroup),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "uuid",
    7,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolCreateReq, uuid),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "sys",
    8,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolCreateReq, sys),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "acl",
    9,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_STRING,
    offsetof(Mgmt__PoolCreateReq, n_acl),
    offsetof(Mgmt__PoolCreateReq, acl),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__pool_create_req__field_indices_by_name[] = {
  8,   /* field[8] = acl */
  3,   /* field[3] = numsvcreps */
  1,   /* field[1] = nvmebytes */
  2,   /* field[2] = ranks */
  0,   /* field[0] = scmbytes */
  7,   /* field[7] = sys */
  4,   /* field[4] = user */
  5,   /* field[5] = usergroup */
  6,   /* field[6] = uuid */
};
static const ProtobufCIntRange mgmt__pool_create_req__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 9 }
};
const ProtobufCMessageDescriptor mgmt__pool_create_req__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.PoolCreateReq",
  "PoolCreateReq",
  "Mgmt__PoolCreateReq",
  "mgmt",
  sizeof(Mgmt__PoolCreateReq),
  9,
  mgmt__pool_create_req__field_descriptors,
  mgmt__pool_create_req__field_indices_by_name,
  1,  mgmt__pool_create_req__number_ranges,
  (ProtobufCMessageInit) mgmt__pool_create_req__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__pool_create_resp__field_descriptors[2] =
{
  {
    "status",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolCreateResp, status),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "svcreps",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Mgmt__PoolCreateResp, n_svcreps),
    offsetof(Mgmt__PoolCreateResp, svcreps),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__pool_create_resp__field_indices_by_name[] = {
  0,   /* field[0] = status */
  1,   /* field[1] = svcreps */
};
static const ProtobufCIntRange mgmt__pool_create_resp__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor mgmt__pool_create_resp__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.PoolCreateResp",
  "PoolCreateResp",
  "Mgmt__PoolCreateResp",
  "mgmt",
  sizeof(Mgmt__PoolCreateResp),
  2,
  mgmt__pool_create_resp__field_descriptors,
  mgmt__pool_create_resp__field_indices_by_name,
  1,  mgmt__pool_create_resp__number_ranges,
  (ProtobufCMessageInit) mgmt__pool_create_resp__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__pool_destroy_req__field_descriptors[3] =
{
  {
    "uuid",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolDestroyReq, uuid),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "sys",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolDestroyReq, sys),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "force",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BOOL,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolDestroyReq, force),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__pool_destroy_req__field_indices_by_name[] = {
  2,   /* field[2] = force */
  1,   /* field[1] = sys */
  0,   /* field[0] = uuid */
};
static const ProtobufCIntRange mgmt__pool_destroy_req__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor mgmt__pool_destroy_req__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.PoolDestroyReq",
  "PoolDestroyReq",
  "Mgmt__PoolDestroyReq",
  "mgmt",
  sizeof(Mgmt__PoolDestroyReq),
  3,
  mgmt__pool_destroy_req__field_descriptors,
  mgmt__pool_destroy_req__field_indices_by_name,
  1,  mgmt__pool_destroy_req__number_ranges,
  (ProtobufCMessageInit) mgmt__pool_destroy_req__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__pool_destroy_resp__field_descriptors[1] =
{
  {
    "status",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolDestroyResp, status),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__pool_destroy_resp__field_indices_by_name[] = {
  0,   /* field[0] = status */
};
static const ProtobufCIntRange mgmt__pool_destroy_resp__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor mgmt__pool_destroy_resp__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.PoolDestroyResp",
  "PoolDestroyResp",
  "Mgmt__PoolDestroyResp",
  "mgmt",
  sizeof(Mgmt__PoolDestroyResp),
  1,
  mgmt__pool_destroy_resp__field_descriptors,
  mgmt__pool_destroy_resp__field_indices_by_name,
  1,  mgmt__pool_destroy_resp__number_ranges,
  (ProtobufCMessageInit) mgmt__pool_destroy_resp__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__list_pools_req__field_descriptors[1] =
{
  {
    "sys",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__ListPoolsReq, sys),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__list_pools_req__field_indices_by_name[] = {
  0,   /* field[0] = sys */
};
static const ProtobufCIntRange mgmt__list_pools_req__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor mgmt__list_pools_req__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.ListPoolsReq",
  "ListPoolsReq",
  "Mgmt__ListPoolsReq",
  "mgmt",
  sizeof(Mgmt__ListPoolsReq),
  1,
  mgmt__list_pools_req__field_descriptors,
  mgmt__list_pools_req__field_indices_by_name,
  1,  mgmt__list_pools_req__number_ranges,
  (ProtobufCMessageInit) mgmt__list_pools_req__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__list_pools_resp__pool__field_descriptors[2] =
{
  {
    "uuid",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__ListPoolsResp__Pool, uuid),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "svcreps",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Mgmt__ListPoolsResp__Pool, n_svcreps),
    offsetof(Mgmt__ListPoolsResp__Pool, svcreps),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__list_pools_resp__pool__field_indices_by_name[] = {
  1,   /* field[1] = svcreps */
  0,   /* field[0] = uuid */
};
static const ProtobufCIntRange mgmt__list_pools_resp__pool__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor mgmt__list_pools_resp__pool__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.ListPoolsResp.Pool",
  "Pool",
  "Mgmt__ListPoolsResp__Pool",
  "mgmt",
  sizeof(Mgmt__ListPoolsResp__Pool),
  2,
  mgmt__list_pools_resp__pool__field_descriptors,
  mgmt__list_pools_resp__pool__field_indices_by_name,
  1,  mgmt__list_pools_resp__pool__number_ranges,
  (ProtobufCMessageInit) mgmt__list_pools_resp__pool__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__list_pools_resp__field_descriptors[2] =
{
  {
    "status",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Mgmt__ListPoolsResp, status),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "pools",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Mgmt__ListPoolsResp, n_pools),
    offsetof(Mgmt__ListPoolsResp, pools),
    &mgmt__list_pools_resp__pool__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__list_pools_resp__field_indices_by_name[] = {
  1,   /* field[1] = pools */
  0,   /* field[0] = status */
};
static const ProtobufCIntRange mgmt__list_pools_resp__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor mgmt__list_pools_resp__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.ListPoolsResp",
  "ListPoolsResp",
  "Mgmt__ListPoolsResp",
  "mgmt",
  sizeof(Mgmt__ListPoolsResp),
  2,
  mgmt__list_pools_resp__field_descriptors,
  mgmt__list_pools_resp__field_indices_by_name,
  1,  mgmt__list_pools_resp__number_ranges,
  (ProtobufCMessageInit) mgmt__list_pools_resp__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__list_cont_req__field_descriptors[1] =
{
  {
    "uuid",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__ListContReq, uuid),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__list_cont_req__field_indices_by_name[] = {
  0,   /* field[0] = uuid */
};
static const ProtobufCIntRange mgmt__list_cont_req__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor mgmt__list_cont_req__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.ListContReq",
  "ListContReq",
  "Mgmt__ListContReq",
  "mgmt",
  sizeof(Mgmt__ListContReq),
  1,
  mgmt__list_cont_req__field_descriptors,
  mgmt__list_cont_req__field_indices_by_name,
  1,  mgmt__list_cont_req__number_ranges,
  (ProtobufCMessageInit) mgmt__list_cont_req__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__list_cont_resp__cont__field_descriptors[1] =
{
  {
    "uuid",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__ListContResp__Cont, uuid),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__list_cont_resp__cont__field_indices_by_name[] = {
  0,   /* field[0] = uuid */
};
static const ProtobufCIntRange mgmt__list_cont_resp__cont__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor mgmt__list_cont_resp__cont__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.ListContResp.Cont",
  "Cont",
  "Mgmt__ListContResp__Cont",
  "mgmt",
  sizeof(Mgmt__ListContResp__Cont),
  1,
  mgmt__list_cont_resp__cont__field_descriptors,
  mgmt__list_cont_resp__cont__field_indices_by_name,
  1,  mgmt__list_cont_resp__cont__number_ranges,
  (ProtobufCMessageInit) mgmt__list_cont_resp__cont__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__list_cont_resp__field_descriptors[2] =
{
  {
    "status",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Mgmt__ListContResp, status),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "containers",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Mgmt__ListContResp, n_containers),
    offsetof(Mgmt__ListContResp, containers),
    &mgmt__list_cont_resp__cont__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__list_cont_resp__field_indices_by_name[] = {
  1,   /* field[1] = containers */
  0,   /* field[0] = status */
};
static const ProtobufCIntRange mgmt__list_cont_resp__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor mgmt__list_cont_resp__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.ListContResp",
  "ListContResp",
  "Mgmt__ListContResp",
  "mgmt",
  sizeof(Mgmt__ListContResp),
  2,
  mgmt__list_cont_resp__field_descriptors,
  mgmt__list_cont_resp__field_indices_by_name,
  1,  mgmt__list_cont_resp__number_ranges,
  (ProtobufCMessageInit) mgmt__list_cont_resp__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__pool_set_prop_req__field_descriptors[5] =
{
  {
    "uuid",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolSetPropReq, uuid),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "name",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    offsetof(Mgmt__PoolSetPropReq, property_case),
    offsetof(Mgmt__PoolSetPropReq, name),
    NULL,
    &protobuf_c_empty_string,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "number",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Mgmt__PoolSetPropReq, property_case),
    offsetof(Mgmt__PoolSetPropReq, number),
    NULL,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "strval",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    offsetof(Mgmt__PoolSetPropReq, value_case),
    offsetof(Mgmt__PoolSetPropReq, strval),
    NULL,
    &protobuf_c_empty_string,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "numval",
    5,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT64,
    offsetof(Mgmt__PoolSetPropReq, value_case),
    offsetof(Mgmt__PoolSetPropReq, numval),
    NULL,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__pool_set_prop_req__field_indices_by_name[] = {
  1,   /* field[1] = name */
  2,   /* field[2] = number */
  4,   /* field[4] = numval */
  3,   /* field[3] = strval */
  0,   /* field[0] = uuid */
};
static const ProtobufCIntRange mgmt__pool_set_prop_req__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 5 }
};
const ProtobufCMessageDescriptor mgmt__pool_set_prop_req__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.PoolSetPropReq",
  "PoolSetPropReq",
  "Mgmt__PoolSetPropReq",
  "mgmt",
  sizeof(Mgmt__PoolSetPropReq),
  5,
  mgmt__pool_set_prop_req__field_descriptors,
  mgmt__pool_set_prop_req__field_indices_by_name,
  1,  mgmt__pool_set_prop_req__number_ranges,
  (ProtobufCMessageInit) mgmt__pool_set_prop_req__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__pool_set_prop_resp__field_descriptors[1] =
{
  {
    "status",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Mgmt__PoolSetPropResp, status),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__pool_set_prop_resp__field_indices_by_name[] = {
  0,   /* field[0] = status */
};
static const ProtobufCIntRange mgmt__pool_set_prop_resp__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor mgmt__pool_set_prop_resp__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.PoolSetPropResp",
  "PoolSetPropResp",
  "Mgmt__PoolSetPropResp",
  "mgmt",
  sizeof(Mgmt__PoolSetPropResp),
  1,
  mgmt__pool_set_prop_resp__field_descriptors,
  mgmt__pool_set_prop_resp__field_indices_by_name,
  1,  mgmt__pool_set_prop_resp__number_ranges,
  (ProtobufCMessageInit) mgmt__pool_set_prop_resp__init,
  NULL,NULL,NULL    /* reserved[123] */
};

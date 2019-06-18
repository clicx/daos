/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: pool.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "pool.pb-c.h"
void   mgmt__create_pool_req__init
                     (Mgmt__CreatePoolReq         *message)
{
  static const Mgmt__CreatePoolReq init_value = MGMT__CREATE_POOL_REQ__INIT;
  *message = init_value;
}
size_t mgmt__create_pool_req__get_packed_size
                     (const Mgmt__CreatePoolReq *message)
{
  assert(message->base.descriptor == &mgmt__create_pool_req__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__create_pool_req__pack
                     (const Mgmt__CreatePoolReq *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__create_pool_req__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__create_pool_req__pack_to_buffer
                     (const Mgmt__CreatePoolReq *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__create_pool_req__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__CreatePoolReq *
       mgmt__create_pool_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__CreatePoolReq *)
     protobuf_c_message_unpack (&mgmt__create_pool_req__descriptor,
                                allocator, len, data);
}
void   mgmt__create_pool_req__free_unpacked
                     (Mgmt__CreatePoolReq *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__create_pool_req__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mgmt__create_pool_resp__init
                     (Mgmt__CreatePoolResp         *message)
{
  static const Mgmt__CreatePoolResp init_value = MGMT__CREATE_POOL_RESP__INIT;
  *message = init_value;
}
size_t mgmt__create_pool_resp__get_packed_size
                     (const Mgmt__CreatePoolResp *message)
{
  assert(message->base.descriptor == &mgmt__create_pool_resp__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mgmt__create_pool_resp__pack
                     (const Mgmt__CreatePoolResp *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mgmt__create_pool_resp__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mgmt__create_pool_resp__pack_to_buffer
                     (const Mgmt__CreatePoolResp *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mgmt__create_pool_resp__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Mgmt__CreatePoolResp *
       mgmt__create_pool_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Mgmt__CreatePoolResp *)
     protobuf_c_message_unpack (&mgmt__create_pool_resp__descriptor,
                                allocator, len, data);
}
void   mgmt__create_pool_resp__free_unpacked
                     (Mgmt__CreatePoolResp *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mgmt__create_pool_resp__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor mgmt__create_pool_req__field_descriptors[7] =
{
  {
    "scmbytes",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    offsetof(Mgmt__CreatePoolReq, scmbytes),
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
    offsetof(Mgmt__CreatePoolReq, nvmebytes),
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
    offsetof(Mgmt__CreatePoolReq, n_ranks),
    offsetof(Mgmt__CreatePoolReq, ranks),
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
    offsetof(Mgmt__CreatePoolReq, numsvcreps),
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
    offsetof(Mgmt__CreatePoolReq, user),
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
    offsetof(Mgmt__CreatePoolReq, usergroup),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "procgroup",
    7,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__CreatePoolReq, procgroup),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__create_pool_req__field_indices_by_name[] = {
  3,   /* field[3] = numsvcreps */
  1,   /* field[1] = nvmebytes */
  6,   /* field[6] = procgroup */
  2,   /* field[2] = ranks */
  0,   /* field[0] = scmbytes */
  4,   /* field[4] = user */
  5,   /* field[5] = usergroup */
};
static const ProtobufCIntRange mgmt__create_pool_req__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 7 }
};
const ProtobufCMessageDescriptor mgmt__create_pool_req__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.CreatePoolReq",
  "CreatePoolReq",
  "Mgmt__CreatePoolReq",
  "mgmt",
  sizeof(Mgmt__CreatePoolReq),
  7,
  mgmt__create_pool_req__field_descriptors,
  mgmt__create_pool_req__field_indices_by_name,
  1,  mgmt__create_pool_req__number_ranges,
  (ProtobufCMessageInit) mgmt__create_pool_req__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mgmt__create_pool_resp__field_descriptors[3] =
{
  {
    "status",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(Mgmt__CreatePoolResp, status),
    &mgmt__daos_request_status__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "uuid",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__CreatePoolResp, uuid),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "ranklist",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Mgmt__CreatePoolResp, ranklist),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mgmt__create_pool_resp__field_indices_by_name[] = {
  2,   /* field[2] = ranklist */
  0,   /* field[0] = status */
  1,   /* field[1] = uuid */
};
static const ProtobufCIntRange mgmt__create_pool_resp__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor mgmt__create_pool_resp__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mgmt.CreatePoolResp",
  "CreatePoolResp",
  "Mgmt__CreatePoolResp",
  "mgmt",
  sizeof(Mgmt__CreatePoolResp),
  3,
  mgmt__create_pool_resp__field_descriptors,
  mgmt__create_pool_resp__field_indices_by_name,
  1,  mgmt__create_pool_resp__number_ranges,
  (ProtobufCMessageInit) mgmt__create_pool_resp__init,
  NULL,NULL,NULL    /* reserved[123] */
};
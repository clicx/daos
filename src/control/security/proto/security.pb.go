// Code generated by protoc-gen-go. DO NOT EDIT.
// source: security.proto

package proto

import (
	fmt "fmt"
	proto "github.com/golang/protobuf/proto"
	math "math"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion2 // please upgrade the proto package

// Authentication token includes a packed structure of the specified flavor
type AuthFlavor int32

const (
	AuthFlavor_AUTH_NONE AuthFlavor = 0
	AuthFlavor_AUTH_SYS  AuthFlavor = 1
)

var AuthFlavor_name = map[int32]string{
	0: "AUTH_NONE",
	1: "AUTH_SYS",
}

var AuthFlavor_value = map[string]int32{
	"AUTH_NONE": 0,
	"AUTH_SYS":  1,
}

func (x AuthFlavor) String() string {
	return proto.EnumName(AuthFlavor_name, int32(x))
}

func (AuthFlavor) EnumDescriptor() ([]byte, []int) {
	return fileDescriptor_55a487c716a8b59c, []int{0}
}

type AuthToken struct {
	Flavor               AuthFlavor `protobuf:"varint,1,opt,name=flavor,proto3,enum=proto.AuthFlavor" json:"flavor,omitempty"`
	Data                 []byte     `protobuf:"bytes,2,opt,name=data,proto3" json:"data,omitempty"`
	XXX_NoUnkeyedLiteral struct{}   `json:"-"`
	XXX_unrecognized     []byte     `json:"-"`
	XXX_sizecache        int32      `json:"-"`
}

func (m *AuthToken) Reset()         { *m = AuthToken{} }
func (m *AuthToken) String() string { return proto.CompactTextString(m) }
func (*AuthToken) ProtoMessage()    {}
func (*AuthToken) Descriptor() ([]byte, []int) {
	return fileDescriptor_55a487c716a8b59c, []int{0}
}

func (m *AuthToken) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_AuthToken.Unmarshal(m, b)
}
func (m *AuthToken) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_AuthToken.Marshal(b, m, deterministic)
}
func (m *AuthToken) XXX_Merge(src proto.Message) {
	xxx_messageInfo_AuthToken.Merge(m, src)
}
func (m *AuthToken) XXX_Size() int {
	return xxx_messageInfo_AuthToken.Size(m)
}
func (m *AuthToken) XXX_DiscardUnknown() {
	xxx_messageInfo_AuthToken.DiscardUnknown(m)
}

var xxx_messageInfo_AuthToken proto.InternalMessageInfo

func (m *AuthToken) GetFlavor() AuthFlavor {
	if m != nil {
		return m.Flavor
	}
	return AuthFlavor_AUTH_NONE
}

func (m *AuthToken) GetData() []byte {
	if m != nil {
		return m.Data
	}
	return nil
}

// Token structure for AUTH_SYS flavor
type AuthSys struct {
	Stamp                uint64   `protobuf:"varint,1,opt,name=stamp,proto3" json:"stamp,omitempty"`
	Machinename          string   `protobuf:"bytes,2,opt,name=machinename,proto3" json:"machinename,omitempty"`
	Uid                  uint32   `protobuf:"varint,3,opt,name=uid,proto3" json:"uid,omitempty"`
	Gid                  uint32   `protobuf:"varint,4,opt,name=gid,proto3" json:"gid,omitempty"`
	Gids                 []uint32 `protobuf:"varint,5,rep,packed,name=gids,proto3" json:"gids,omitempty"`
	Secctx               string   `protobuf:"bytes,6,opt,name=secctx,proto3" json:"secctx,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *AuthSys) Reset()         { *m = AuthSys{} }
func (m *AuthSys) String() string { return proto.CompactTextString(m) }
func (*AuthSys) ProtoMessage()    {}
func (*AuthSys) Descriptor() ([]byte, []int) {
	return fileDescriptor_55a487c716a8b59c, []int{1}
}

func (m *AuthSys) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_AuthSys.Unmarshal(m, b)
}
func (m *AuthSys) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_AuthSys.Marshal(b, m, deterministic)
}
func (m *AuthSys) XXX_Merge(src proto.Message) {
	xxx_messageInfo_AuthSys.Merge(m, src)
}
func (m *AuthSys) XXX_Size() int {
	return xxx_messageInfo_AuthSys.Size(m)
}
func (m *AuthSys) XXX_DiscardUnknown() {
	xxx_messageInfo_AuthSys.DiscardUnknown(m)
}

var xxx_messageInfo_AuthSys proto.InternalMessageInfo

func (m *AuthSys) GetStamp() uint64 {
	if m != nil {
		return m.Stamp
	}
	return 0
}

func (m *AuthSys) GetMachinename() string {
	if m != nil {
		return m.Machinename
	}
	return ""
}

func (m *AuthSys) GetUid() uint32 {
	if m != nil {
		return m.Uid
	}
	return 0
}

func (m *AuthSys) GetGid() uint32 {
	if m != nil {
		return m.Gid
	}
	return 0
}

func (m *AuthSys) GetGids() []uint32 {
	if m != nil {
		return m.Gids
	}
	return nil
}

func (m *AuthSys) GetSecctx() string {
	if m != nil {
		return m.Secctx
	}
	return ""
}

type AuthSysVerifier struct {
	Signature            []byte   `protobuf:"bytes,1,opt,name=signature,proto3" json:"signature,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *AuthSysVerifier) Reset()         { *m = AuthSysVerifier{} }
func (m *AuthSysVerifier) String() string { return proto.CompactTextString(m) }
func (*AuthSysVerifier) ProtoMessage()    {}
func (*AuthSysVerifier) Descriptor() ([]byte, []int) {
	return fileDescriptor_55a487c716a8b59c, []int{2}
}

func (m *AuthSysVerifier) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_AuthSysVerifier.Unmarshal(m, b)
}
func (m *AuthSysVerifier) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_AuthSysVerifier.Marshal(b, m, deterministic)
}
func (m *AuthSysVerifier) XXX_Merge(src proto.Message) {
	xxx_messageInfo_AuthSysVerifier.Merge(m, src)
}
func (m *AuthSysVerifier) XXX_Size() int {
	return xxx_messageInfo_AuthSysVerifier.Size(m)
}
func (m *AuthSysVerifier) XXX_DiscardUnknown() {
	xxx_messageInfo_AuthSysVerifier.DiscardUnknown(m)
}

var xxx_messageInfo_AuthSysVerifier proto.InternalMessageInfo

func (m *AuthSysVerifier) GetSignature() []byte {
	if m != nil {
		return m.Signature
	}
	return nil
}

// SecurityCredential includes the auth token and a verifier that can be used by
// the server to verify the integrity of the token.
// Token and verifier are expected to have the same flavor type.
type SecurityCredential struct {
	Token                *AuthToken `protobuf:"bytes,1,opt,name=token,proto3" json:"token,omitempty"`
	Verifier             *AuthToken `protobuf:"bytes,2,opt,name=verifier,proto3" json:"verifier,omitempty"`
	XXX_NoUnkeyedLiteral struct{}   `json:"-"`
	XXX_unrecognized     []byte     `json:"-"`
	XXX_sizecache        int32      `json:"-"`
}

func (m *SecurityCredential) Reset()         { *m = SecurityCredential{} }
func (m *SecurityCredential) String() string { return proto.CompactTextString(m) }
func (*SecurityCredential) ProtoMessage()    {}
func (*SecurityCredential) Descriptor() ([]byte, []int) {
	return fileDescriptor_55a487c716a8b59c, []int{3}
}

func (m *SecurityCredential) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_SecurityCredential.Unmarshal(m, b)
}
func (m *SecurityCredential) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_SecurityCredential.Marshal(b, m, deterministic)
}
func (m *SecurityCredential) XXX_Merge(src proto.Message) {
	xxx_messageInfo_SecurityCredential.Merge(m, src)
}
func (m *SecurityCredential) XXX_Size() int {
	return xxx_messageInfo_SecurityCredential.Size(m)
}
func (m *SecurityCredential) XXX_DiscardUnknown() {
	xxx_messageInfo_SecurityCredential.DiscardUnknown(m)
}

var xxx_messageInfo_SecurityCredential proto.InternalMessageInfo

func (m *SecurityCredential) GetToken() *AuthToken {
	if m != nil {
		return m.Token
	}
	return nil
}

func (m *SecurityCredential) GetVerifier() *AuthToken {
	if m != nil {
		return m.Verifier
	}
	return nil
}

func init() {
	proto.RegisterEnum("proto.AuthFlavor", AuthFlavor_name, AuthFlavor_value)
	proto.RegisterType((*AuthToken)(nil), "proto.AuthToken")
	proto.RegisterType((*AuthSys)(nil), "proto.AuthSys")
	proto.RegisterType((*AuthSysVerifier)(nil), "proto.AuthSysVerifier")
	proto.RegisterType((*SecurityCredential)(nil), "proto.SecurityCredential")
}

func init() { proto.RegisterFile("security.proto", fileDescriptor_55a487c716a8b59c) }

var fileDescriptor_55a487c716a8b59c = []byte{
	// 314 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x6c, 0x90, 0x4f, 0x4f, 0xb3, 0x40,
	0x10, 0xc6, 0x5f, 0xde, 0x16, 0x2c, 0xd3, 0x3f, 0xe2, 0xc4, 0x18, 0x0e, 0x1e, 0x08, 0x07, 0x43,
	0x8d, 0xa9, 0x49, 0xfd, 0x04, 0x8d, 0xd1, 0x18, 0x0f, 0x35, 0x59, 0xaa, 0x89, 0x27, 0xb3, 0xc2,
	0x96, 0xae, 0x16, 0x68, 0x96, 0xa5, 0xb1, 0x1f, 0xc3, 0x6f, 0x6c, 0x76, 0x20, 0xb6, 0x07, 0x4f,
	0xcc, 0x3c, 0xf3, 0xe3, 0x99, 0xd9, 0x07, 0x46, 0x95, 0x48, 0x6a, 0x25, 0xf5, 0x6e, 0xb2, 0x51,
	0xa5, 0x2e, 0xd1, 0xa6, 0x4f, 0xf8, 0x08, 0xee, 0xac, 0xd6, 0xab, 0x45, 0xf9, 0x29, 0x0a, 0x1c,
	0x83, 0xb3, 0x5c, 0xf3, 0x6d, 0xa9, 0x7c, 0x2b, 0xb0, 0xa2, 0xd1, 0xf4, 0xa4, 0x61, 0x27, 0x86,
	0xb8, 0xa7, 0x01, 0x6b, 0x01, 0x44, 0xe8, 0xa6, 0x5c, 0x73, 0xff, 0x7f, 0x60, 0x45, 0x03, 0x46,
	0x75, 0xf8, 0x6d, 0xc1, 0x91, 0x41, 0xe3, 0x5d, 0x85, 0xa7, 0x60, 0x57, 0x9a, 0xe7, 0x1b, 0x72,
	0xea, 0xb2, 0xa6, 0xc1, 0x00, 0xfa, 0x39, 0x4f, 0x56, 0xb2, 0x10, 0x05, 0xcf, 0x05, 0xfd, 0xec,
	0xb2, 0x43, 0x09, 0x3d, 0xe8, 0xd4, 0x32, 0xf5, 0x3b, 0x81, 0x15, 0x0d, 0x99, 0x29, 0x8d, 0x92,
	0xc9, 0xd4, 0xef, 0x36, 0x4a, 0x26, 0x53, 0xb3, 0x3b, 0x93, 0x69, 0xe5, 0xdb, 0x41, 0x27, 0x1a,
	0x32, 0xaa, 0xf1, 0x0c, 0x9c, 0x4a, 0x24, 0x89, 0xfe, 0xf2, 0x1d, 0x32, 0x6d, 0xbb, 0xf0, 0x1a,
	0x8e, 0xdb, 0x93, 0x5e, 0x84, 0x92, 0x4b, 0x29, 0x14, 0x9e, 0x83, 0x5b, 0xc9, 0xac, 0xe0, 0xba,
	0x56, 0x82, 0xce, 0x1b, 0xb0, 0xbd, 0x10, 0x7e, 0x00, 0xc6, 0x6d, 0x52, 0xb7, 0x4a, 0xa4, 0xa2,
	0xd0, 0x92, 0xaf, 0xf1, 0x02, 0x6c, 0x6d, 0x22, 0x22, 0xbe, 0x3f, 0xf5, 0x0e, 0x82, 0xa1, 0xe8,
	0x58, 0x33, 0xc6, 0x2b, 0xe8, 0x6d, 0xdb, 0x3d, 0xf4, 0xba, 0xbf, 0xd0, 0x5f, 0xe2, 0x72, 0x0c,
	0xb0, 0x8f, 0x16, 0x87, 0xe0, 0xce, 0x9e, 0x17, 0x0f, 0x6f, 0xf3, 0xa7, 0xf9, 0x9d, 0xf7, 0x0f,
	0x07, 0xd0, 0xa3, 0x36, 0x7e, 0x8d, 0x3d, 0xeb, 0xdd, 0x21, 0x97, 0x9b, 0x9f, 0x00, 0x00, 0x00,
	0xff, 0xff, 0x52, 0xfd, 0x15, 0x93, 0xc7, 0x01, 0x00, 0x00,
}

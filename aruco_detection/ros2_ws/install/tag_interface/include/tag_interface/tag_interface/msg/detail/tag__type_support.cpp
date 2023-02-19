// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tag_interface:msg/Tag.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tag_interface/msg/detail/tag__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tag_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Tag_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tag_interface::msg::Tag(_init);
}

void Tag_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tag_interface::msg::Tag *>(message_memory);
  typed_message->~Tag();
}

size_t size_function__Tag__id(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Tag__id(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void * get_function__Tag__id(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__Tag__id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int64_t *>(
    get_const_function__Tag__id(untyped_member, index));
  auto & value = *reinterpret_cast<int64_t *>(untyped_value);
  value = item;
}

void assign_function__Tag__id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int64_t *>(
    get_function__Tag__id(untyped_member, index));
  const auto & value = *reinterpret_cast<const int64_t *>(untyped_value);
  item = value;
}

void resize_function__Tag__id(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Tag__top_right(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Tag__top_right(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return &member[index];
}

void * get_function__Tag__top_right(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return &member[index];
}

void fetch_function__Tag__top_right(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tag_interface::msg::Coordinate *>(
    get_const_function__Tag__top_right(untyped_member, index));
  auto & value = *reinterpret_cast<tag_interface::msg::Coordinate *>(untyped_value);
  value = item;
}

void assign_function__Tag__top_right(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tag_interface::msg::Coordinate *>(
    get_function__Tag__top_right(untyped_member, index));
  const auto & value = *reinterpret_cast<const tag_interface::msg::Coordinate *>(untyped_value);
  item = value;
}

void resize_function__Tag__top_right(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Tag__top_left(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Tag__top_left(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return &member[index];
}

void * get_function__Tag__top_left(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return &member[index];
}

void fetch_function__Tag__top_left(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tag_interface::msg::Coordinate *>(
    get_const_function__Tag__top_left(untyped_member, index));
  auto & value = *reinterpret_cast<tag_interface::msg::Coordinate *>(untyped_value);
  value = item;
}

void assign_function__Tag__top_left(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tag_interface::msg::Coordinate *>(
    get_function__Tag__top_left(untyped_member, index));
  const auto & value = *reinterpret_cast<const tag_interface::msg::Coordinate *>(untyped_value);
  item = value;
}

void resize_function__Tag__top_left(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Tag__bottom_right(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Tag__bottom_right(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return &member[index];
}

void * get_function__Tag__bottom_right(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return &member[index];
}

void fetch_function__Tag__bottom_right(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tag_interface::msg::Coordinate *>(
    get_const_function__Tag__bottom_right(untyped_member, index));
  auto & value = *reinterpret_cast<tag_interface::msg::Coordinate *>(untyped_value);
  value = item;
}

void assign_function__Tag__bottom_right(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tag_interface::msg::Coordinate *>(
    get_function__Tag__bottom_right(untyped_member, index));
  const auto & value = *reinterpret_cast<const tag_interface::msg::Coordinate *>(untyped_value);
  item = value;
}

void resize_function__Tag__bottom_right(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Tag__bottom_left(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Tag__bottom_left(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return &member[index];
}

void * get_function__Tag__bottom_left(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  return &member[index];
}

void fetch_function__Tag__bottom_left(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tag_interface::msg::Coordinate *>(
    get_const_function__Tag__bottom_left(untyped_member, index));
  auto & value = *reinterpret_cast<tag_interface::msg::Coordinate *>(untyped_value);
  value = item;
}

void assign_function__Tag__bottom_left(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tag_interface::msg::Coordinate *>(
    get_function__Tag__bottom_left(untyped_member, index));
  const auto & value = *reinterpret_cast<const tag_interface::msg::Coordinate *>(untyped_value);
  item = value;
}

void resize_function__Tag__bottom_left(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tag_interface::msg::Coordinate> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Tag__position(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Tag__position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void * get_function__Tag__position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__Tag__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int64_t *>(
    get_const_function__Tag__position(untyped_member, index));
  auto & value = *reinterpret_cast<int64_t *>(untyped_value);
  value = item;
}

void assign_function__Tag__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int64_t *>(
    get_function__Tag__position(untyped_member, index));
  const auto & value = *reinterpret_cast<const int64_t *>(untyped_value);
  item = value;
}

void resize_function__Tag__position(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Tag__distance(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Tag__distance(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Tag__distance(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__Tag__distance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Tag__distance(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Tag__distance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Tag__distance(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__Tag__distance(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Tag_message_member_array[7] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface::msg::Tag, id),  // bytes offset in struct
    nullptr,  // default value
    size_function__Tag__id,  // size() function pointer
    get_const_function__Tag__id,  // get_const(index) function pointer
    get_function__Tag__id,  // get(index) function pointer
    fetch_function__Tag__id,  // fetch(index, &value) function pointer
    assign_function__Tag__id,  // assign(index, value) function pointer
    resize_function__Tag__id  // resize(index) function pointer
  },
  {
    "top_right",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tag_interface::msg::Coordinate>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface::msg::Tag, top_right),  // bytes offset in struct
    nullptr,  // default value
    size_function__Tag__top_right,  // size() function pointer
    get_const_function__Tag__top_right,  // get_const(index) function pointer
    get_function__Tag__top_right,  // get(index) function pointer
    fetch_function__Tag__top_right,  // fetch(index, &value) function pointer
    assign_function__Tag__top_right,  // assign(index, value) function pointer
    resize_function__Tag__top_right  // resize(index) function pointer
  },
  {
    "top_left",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tag_interface::msg::Coordinate>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface::msg::Tag, top_left),  // bytes offset in struct
    nullptr,  // default value
    size_function__Tag__top_left,  // size() function pointer
    get_const_function__Tag__top_left,  // get_const(index) function pointer
    get_function__Tag__top_left,  // get(index) function pointer
    fetch_function__Tag__top_left,  // fetch(index, &value) function pointer
    assign_function__Tag__top_left,  // assign(index, value) function pointer
    resize_function__Tag__top_left  // resize(index) function pointer
  },
  {
    "bottom_right",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tag_interface::msg::Coordinate>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface::msg::Tag, bottom_right),  // bytes offset in struct
    nullptr,  // default value
    size_function__Tag__bottom_right,  // size() function pointer
    get_const_function__Tag__bottom_right,  // get_const(index) function pointer
    get_function__Tag__bottom_right,  // get(index) function pointer
    fetch_function__Tag__bottom_right,  // fetch(index, &value) function pointer
    assign_function__Tag__bottom_right,  // assign(index, value) function pointer
    resize_function__Tag__bottom_right  // resize(index) function pointer
  },
  {
    "bottom_left",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tag_interface::msg::Coordinate>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface::msg::Tag, bottom_left),  // bytes offset in struct
    nullptr,  // default value
    size_function__Tag__bottom_left,  // size() function pointer
    get_const_function__Tag__bottom_left,  // get_const(index) function pointer
    get_function__Tag__bottom_left,  // get(index) function pointer
    fetch_function__Tag__bottom_left,  // fetch(index, &value) function pointer
    assign_function__Tag__bottom_left,  // assign(index, value) function pointer
    resize_function__Tag__bottom_left  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface::msg::Tag, position),  // bytes offset in struct
    nullptr,  // default value
    size_function__Tag__position,  // size() function pointer
    get_const_function__Tag__position,  // get_const(index) function pointer
    get_function__Tag__position,  // get(index) function pointer
    fetch_function__Tag__position,  // fetch(index, &value) function pointer
    assign_function__Tag__position,  // assign(index, value) function pointer
    resize_function__Tag__position  // resize(index) function pointer
  },
  {
    "distance",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface::msg::Tag, distance),  // bytes offset in struct
    nullptr,  // default value
    size_function__Tag__distance,  // size() function pointer
    get_const_function__Tag__distance,  // get_const(index) function pointer
    get_function__Tag__distance,  // get(index) function pointer
    fetch_function__Tag__distance,  // fetch(index, &value) function pointer
    assign_function__Tag__distance,  // assign(index, value) function pointer
    resize_function__Tag__distance  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Tag_message_members = {
  "tag_interface::msg",  // message namespace
  "Tag",  // message name
  7,  // number of fields
  sizeof(tag_interface::msg::Tag),
  Tag_message_member_array,  // message members
  Tag_init_function,  // function to initialize message memory (memory has to be allocated)
  Tag_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Tag_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Tag_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tag_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tag_interface::msg::Tag>()
{
  return &::tag_interface::msg::rosidl_typesupport_introspection_cpp::Tag_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tag_interface, msg, Tag)() {
  return &::tag_interface::msg::rosidl_typesupport_introspection_cpp::Tag_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

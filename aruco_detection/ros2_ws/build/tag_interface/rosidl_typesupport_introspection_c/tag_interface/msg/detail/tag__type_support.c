// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tag_interface:msg/Tag.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tag_interface/msg/detail/tag__rosidl_typesupport_introspection_c.h"
#include "tag_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tag_interface/msg/detail/tag__functions.h"
#include "tag_interface/msg/detail/tag__struct.h"


// Include directives for member types
// Member `id`
// Member `position`
// Member `distance`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `top_right`
// Member `top_left`
// Member `bottom_right`
// Member `bottom_left`
#include "tag_interface/msg/coordinate.h"
// Member `top_right`
// Member `top_left`
// Member `bottom_right`
// Member `bottom_left`
#include "tag_interface/msg/detail/coordinate__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tag_interface__msg__Tag__init(message_memory);
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_fini_function(void * message_memory)
{
  tag_interface__msg__Tag__fini(message_memory);
}

size_t tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__id(
  const void * untyped_member)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return member->size;
}

const void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__id(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__id(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int64_t * item =
    ((const int64_t *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__id(untyped_member, index));
  int64_t * value =
    (int64_t *)(untyped_value);
  *value = *item;
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int64_t * item =
    ((int64_t *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__id(untyped_member, index));
  const int64_t * value =
    (const int64_t *)(untyped_value);
  *item = *value;
}

bool tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__id(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  rosidl_runtime_c__int64__Sequence__fini(member);
  return rosidl_runtime_c__int64__Sequence__init(member, size);
}

size_t tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__top_right(
  const void * untyped_member)
{
  const tag_interface__msg__Coordinate__Sequence * member =
    (const tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return member->size;
}

const void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__top_right(
  const void * untyped_member, size_t index)
{
  const tag_interface__msg__Coordinate__Sequence * member =
    (const tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__top_right(
  void * untyped_member, size_t index)
{
  tag_interface__msg__Coordinate__Sequence * member =
    (tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__top_right(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tag_interface__msg__Coordinate * item =
    ((const tag_interface__msg__Coordinate *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__top_right(untyped_member, index));
  tag_interface__msg__Coordinate * value =
    (tag_interface__msg__Coordinate *)(untyped_value);
  *value = *item;
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__top_right(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tag_interface__msg__Coordinate * item =
    ((tag_interface__msg__Coordinate *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__top_right(untyped_member, index));
  const tag_interface__msg__Coordinate * value =
    (const tag_interface__msg__Coordinate *)(untyped_value);
  *item = *value;
}

bool tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__top_right(
  void * untyped_member, size_t size)
{
  tag_interface__msg__Coordinate__Sequence * member =
    (tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  tag_interface__msg__Coordinate__Sequence__fini(member);
  return tag_interface__msg__Coordinate__Sequence__init(member, size);
}

size_t tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__top_left(
  const void * untyped_member)
{
  const tag_interface__msg__Coordinate__Sequence * member =
    (const tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return member->size;
}

const void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__top_left(
  const void * untyped_member, size_t index)
{
  const tag_interface__msg__Coordinate__Sequence * member =
    (const tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__top_left(
  void * untyped_member, size_t index)
{
  tag_interface__msg__Coordinate__Sequence * member =
    (tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__top_left(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tag_interface__msg__Coordinate * item =
    ((const tag_interface__msg__Coordinate *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__top_left(untyped_member, index));
  tag_interface__msg__Coordinate * value =
    (tag_interface__msg__Coordinate *)(untyped_value);
  *value = *item;
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__top_left(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tag_interface__msg__Coordinate * item =
    ((tag_interface__msg__Coordinate *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__top_left(untyped_member, index));
  const tag_interface__msg__Coordinate * value =
    (const tag_interface__msg__Coordinate *)(untyped_value);
  *item = *value;
}

bool tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__top_left(
  void * untyped_member, size_t size)
{
  tag_interface__msg__Coordinate__Sequence * member =
    (tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  tag_interface__msg__Coordinate__Sequence__fini(member);
  return tag_interface__msg__Coordinate__Sequence__init(member, size);
}

size_t tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__bottom_right(
  const void * untyped_member)
{
  const tag_interface__msg__Coordinate__Sequence * member =
    (const tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return member->size;
}

const void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__bottom_right(
  const void * untyped_member, size_t index)
{
  const tag_interface__msg__Coordinate__Sequence * member =
    (const tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__bottom_right(
  void * untyped_member, size_t index)
{
  tag_interface__msg__Coordinate__Sequence * member =
    (tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__bottom_right(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tag_interface__msg__Coordinate * item =
    ((const tag_interface__msg__Coordinate *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__bottom_right(untyped_member, index));
  tag_interface__msg__Coordinate * value =
    (tag_interface__msg__Coordinate *)(untyped_value);
  *value = *item;
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__bottom_right(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tag_interface__msg__Coordinate * item =
    ((tag_interface__msg__Coordinate *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__bottom_right(untyped_member, index));
  const tag_interface__msg__Coordinate * value =
    (const tag_interface__msg__Coordinate *)(untyped_value);
  *item = *value;
}

bool tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__bottom_right(
  void * untyped_member, size_t size)
{
  tag_interface__msg__Coordinate__Sequence * member =
    (tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  tag_interface__msg__Coordinate__Sequence__fini(member);
  return tag_interface__msg__Coordinate__Sequence__init(member, size);
}

size_t tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__bottom_left(
  const void * untyped_member)
{
  const tag_interface__msg__Coordinate__Sequence * member =
    (const tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return member->size;
}

const void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__bottom_left(
  const void * untyped_member, size_t index)
{
  const tag_interface__msg__Coordinate__Sequence * member =
    (const tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__bottom_left(
  void * untyped_member, size_t index)
{
  tag_interface__msg__Coordinate__Sequence * member =
    (tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__bottom_left(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tag_interface__msg__Coordinate * item =
    ((const tag_interface__msg__Coordinate *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__bottom_left(untyped_member, index));
  tag_interface__msg__Coordinate * value =
    (tag_interface__msg__Coordinate *)(untyped_value);
  *value = *item;
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__bottom_left(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tag_interface__msg__Coordinate * item =
    ((tag_interface__msg__Coordinate *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__bottom_left(untyped_member, index));
  const tag_interface__msg__Coordinate * value =
    (const tag_interface__msg__Coordinate *)(untyped_value);
  *item = *value;
}

bool tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__bottom_left(
  void * untyped_member, size_t size)
{
  tag_interface__msg__Coordinate__Sequence * member =
    (tag_interface__msg__Coordinate__Sequence *)(untyped_member);
  tag_interface__msg__Coordinate__Sequence__fini(member);
  return tag_interface__msg__Coordinate__Sequence__init(member, size);
}

size_t tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__position(
  const void * untyped_member)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return member->size;
}

const void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__position(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__position(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int64_t * item =
    ((const int64_t *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__position(untyped_member, index));
  int64_t * value =
    (int64_t *)(untyped_value);
  *value = *item;
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int64_t * item =
    ((int64_t *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__position(untyped_member, index));
  const int64_t * value =
    (const int64_t *)(untyped_value);
  *item = *value;
}

bool tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__position(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  rosidl_runtime_c__int64__Sequence__fini(member);
  return rosidl_runtime_c__int64__Sequence__init(member, size);
}

size_t tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__distance(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__distance(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__distance(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__distance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__distance(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__distance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__distance(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__distance(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_member_array[7] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface__msg__Tag, id),  // bytes offset in struct
    NULL,  // default value
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__id,  // size() function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__id,  // get_const(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__id,  // get(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__id,  // fetch(index, &value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__id,  // assign(index, value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__id  // resize(index) function pointer
  },
  {
    "top_right",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface__msg__Tag, top_right),  // bytes offset in struct
    NULL,  // default value
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__top_right,  // size() function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__top_right,  // get_const(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__top_right,  // get(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__top_right,  // fetch(index, &value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__top_right,  // assign(index, value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__top_right  // resize(index) function pointer
  },
  {
    "top_left",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface__msg__Tag, top_left),  // bytes offset in struct
    NULL,  // default value
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__top_left,  // size() function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__top_left,  // get_const(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__top_left,  // get(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__top_left,  // fetch(index, &value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__top_left,  // assign(index, value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__top_left  // resize(index) function pointer
  },
  {
    "bottom_right",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface__msg__Tag, bottom_right),  // bytes offset in struct
    NULL,  // default value
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__bottom_right,  // size() function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__bottom_right,  // get_const(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__bottom_right,  // get(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__bottom_right,  // fetch(index, &value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__bottom_right,  // assign(index, value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__bottom_right  // resize(index) function pointer
  },
  {
    "bottom_left",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface__msg__Tag, bottom_left),  // bytes offset in struct
    NULL,  // default value
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__bottom_left,  // size() function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__bottom_left,  // get_const(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__bottom_left,  // get(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__bottom_left,  // fetch(index, &value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__bottom_left,  // assign(index, value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__bottom_left  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface__msg__Tag, position),  // bytes offset in struct
    NULL,  // default value
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__position,  // size() function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__position,  // get_const(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__position,  // get(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__position,  // fetch(index, &value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__position,  // assign(index, value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__position  // resize(index) function pointer
  },
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tag_interface__msg__Tag, distance),  // bytes offset in struct
    NULL,  // default value
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__size_function__Tag__distance,  // size() function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_const_function__Tag__distance,  // get_const(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__get_function__Tag__distance,  // get(index) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__fetch_function__Tag__distance,  // fetch(index, &value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__assign_function__Tag__distance,  // assign(index, value) function pointer
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__resize_function__Tag__distance  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_members = {
  "tag_interface__msg",  // message namespace
  "Tag",  // message name
  7,  // number of fields
  sizeof(tag_interface__msg__Tag),
  tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_member_array,  // message members
  tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_init_function,  // function to initialize message memory (memory has to be allocated)
  tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_type_support_handle = {
  0,
  &tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tag_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tag_interface, msg, Tag)() {
  tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tag_interface, msg, Coordinate)();
  tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tag_interface, msg, Coordinate)();
  tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tag_interface, msg, Coordinate)();
  tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tag_interface, msg, Coordinate)();
  if (!tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_type_support_handle.typesupport_identifier) {
    tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tag_interface__msg__Tag__rosidl_typesupport_introspection_c__Tag_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

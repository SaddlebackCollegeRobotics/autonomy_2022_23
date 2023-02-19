// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tag_interface:msg/Tag.idl
// generated code does not contain a copyright notice

#ifndef TAG_INTERFACE__MSG__DETAIL__TAG__STRUCT_H_
#define TAG_INTERFACE__MSG__DETAIL__TAG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'id'
// Member 'position'
// Member 'distance'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'top_right'
// Member 'top_left'
// Member 'bottom_right'
// Member 'bottom_left'
#include "tag_interface/msg/detail/coordinate__struct.h"

/// Struct defined in msg/Tag in the package tag_interface.
typedef struct tag_interface__msg__Tag
{
  rosidl_runtime_c__int64__Sequence id;
  tag_interface__msg__Coordinate__Sequence top_right;
  tag_interface__msg__Coordinate__Sequence top_left;
  tag_interface__msg__Coordinate__Sequence bottom_right;
  tag_interface__msg__Coordinate__Sequence bottom_left;
  rosidl_runtime_c__int64__Sequence position;
  rosidl_runtime_c__double__Sequence distance;
} tag_interface__msg__Tag;

// Struct for a sequence of tag_interface__msg__Tag.
typedef struct tag_interface__msg__Tag__Sequence
{
  tag_interface__msg__Tag * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tag_interface__msg__Tag__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TAG_INTERFACE__MSG__DETAIL__TAG__STRUCT_H_

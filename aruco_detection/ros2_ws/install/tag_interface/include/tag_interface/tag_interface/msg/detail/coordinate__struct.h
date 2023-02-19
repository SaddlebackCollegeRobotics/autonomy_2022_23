// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tag_interface:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef TAG_INTERFACE__MSG__DETAIL__COORDINATE__STRUCT_H_
#define TAG_INTERFACE__MSG__DETAIL__COORDINATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Coordinate in the package tag_interface.
typedef struct tag_interface__msg__Coordinate
{
  int64_t row;
  int64_t col;
} tag_interface__msg__Coordinate;

// Struct for a sequence of tag_interface__msg__Coordinate.
typedef struct tag_interface__msg__Coordinate__Sequence
{
  tag_interface__msg__Coordinate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tag_interface__msg__Coordinate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TAG_INTERFACE__MSG__DETAIL__COORDINATE__STRUCT_H_

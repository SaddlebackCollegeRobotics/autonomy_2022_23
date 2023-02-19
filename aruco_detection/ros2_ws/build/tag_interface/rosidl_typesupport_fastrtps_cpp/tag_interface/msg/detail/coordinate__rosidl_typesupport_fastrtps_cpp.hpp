// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from tag_interface:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef TAG_INTERFACE__MSG__DETAIL__COORDINATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TAG_INTERFACE__MSG__DETAIL__COORDINATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "tag_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "tag_interface/msg/detail/coordinate__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace tag_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tag_interface
cdr_serialize(
  const tag_interface::msg::Coordinate & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tag_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tag_interface::msg::Coordinate & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tag_interface
get_serialized_size(
  const tag_interface::msg::Coordinate & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tag_interface
max_serialized_size_Coordinate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace tag_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tag_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tag_interface, msg, Coordinate)();

#ifdef __cplusplus
}
#endif

#endif  // TAG_INTERFACE__MSG__DETAIL__COORDINATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

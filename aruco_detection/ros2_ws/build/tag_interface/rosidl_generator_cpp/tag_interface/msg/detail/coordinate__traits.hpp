// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tag_interface:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef TAG_INTERFACE__MSG__DETAIL__COORDINATE__TRAITS_HPP_
#define TAG_INTERFACE__MSG__DETAIL__COORDINATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tag_interface/msg/detail/coordinate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tag_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Coordinate & msg,
  std::ostream & out)
{
  out << "{";
  // member: row
  {
    out << "row: ";
    rosidl_generator_traits::value_to_yaml(msg.row, out);
    out << ", ";
  }

  // member: col
  {
    out << "col: ";
    rosidl_generator_traits::value_to_yaml(msg.col, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Coordinate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: row
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "row: ";
    rosidl_generator_traits::value_to_yaml(msg.row, out);
    out << "\n";
  }

  // member: col
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "col: ";
    rosidl_generator_traits::value_to_yaml(msg.col, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Coordinate & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tag_interface

namespace rosidl_generator_traits
{

[[deprecated("use tag_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tag_interface::msg::Coordinate & msg,
  std::ostream & out, size_t indentation = 0)
{
  tag_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tag_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const tag_interface::msg::Coordinate & msg)
{
  return tag_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tag_interface::msg::Coordinate>()
{
  return "tag_interface::msg::Coordinate";
}

template<>
inline const char * name<tag_interface::msg::Coordinate>()
{
  return "tag_interface/msg/Coordinate";
}

template<>
struct has_fixed_size<tag_interface::msg::Coordinate>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tag_interface::msg::Coordinate>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tag_interface::msg::Coordinate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TAG_INTERFACE__MSG__DETAIL__COORDINATE__TRAITS_HPP_

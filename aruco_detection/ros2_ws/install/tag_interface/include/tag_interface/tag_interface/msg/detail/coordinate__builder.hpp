// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tag_interface:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef TAG_INTERFACE__MSG__DETAIL__COORDINATE__BUILDER_HPP_
#define TAG_INTERFACE__MSG__DETAIL__COORDINATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tag_interface/msg/detail/coordinate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tag_interface
{

namespace msg
{

namespace builder
{

class Init_Coordinate_col
{
public:
  explicit Init_Coordinate_col(::tag_interface::msg::Coordinate & msg)
  : msg_(msg)
  {}
  ::tag_interface::msg::Coordinate col(::tag_interface::msg::Coordinate::_col_type arg)
  {
    msg_.col = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tag_interface::msg::Coordinate msg_;
};

class Init_Coordinate_row
{
public:
  Init_Coordinate_row()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coordinate_col row(::tag_interface::msg::Coordinate::_row_type arg)
  {
    msg_.row = std::move(arg);
    return Init_Coordinate_col(msg_);
  }

private:
  ::tag_interface::msg::Coordinate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tag_interface::msg::Coordinate>()
{
  return tag_interface::msg::builder::Init_Coordinate_row();
}

}  // namespace tag_interface

#endif  // TAG_INTERFACE__MSG__DETAIL__COORDINATE__BUILDER_HPP_

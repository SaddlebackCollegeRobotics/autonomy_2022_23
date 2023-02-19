// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tag_interface:msg/Tag.idl
// generated code does not contain a copyright notice

#ifndef TAG_INTERFACE__MSG__DETAIL__TAG__BUILDER_HPP_
#define TAG_INTERFACE__MSG__DETAIL__TAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tag_interface/msg/detail/tag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tag_interface
{

namespace msg
{

namespace builder
{

class Init_Tag_distance
{
public:
  explicit Init_Tag_distance(::tag_interface::msg::Tag & msg)
  : msg_(msg)
  {}
  ::tag_interface::msg::Tag distance(::tag_interface::msg::Tag::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tag_interface::msg::Tag msg_;
};

class Init_Tag_position
{
public:
  explicit Init_Tag_position(::tag_interface::msg::Tag & msg)
  : msg_(msg)
  {}
  Init_Tag_distance position(::tag_interface::msg::Tag::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Tag_distance(msg_);
  }

private:
  ::tag_interface::msg::Tag msg_;
};

class Init_Tag_bottom_left
{
public:
  explicit Init_Tag_bottom_left(::tag_interface::msg::Tag & msg)
  : msg_(msg)
  {}
  Init_Tag_position bottom_left(::tag_interface::msg::Tag::_bottom_left_type arg)
  {
    msg_.bottom_left = std::move(arg);
    return Init_Tag_position(msg_);
  }

private:
  ::tag_interface::msg::Tag msg_;
};

class Init_Tag_bottom_right
{
public:
  explicit Init_Tag_bottom_right(::tag_interface::msg::Tag & msg)
  : msg_(msg)
  {}
  Init_Tag_bottom_left bottom_right(::tag_interface::msg::Tag::_bottom_right_type arg)
  {
    msg_.bottom_right = std::move(arg);
    return Init_Tag_bottom_left(msg_);
  }

private:
  ::tag_interface::msg::Tag msg_;
};

class Init_Tag_top_left
{
public:
  explicit Init_Tag_top_left(::tag_interface::msg::Tag & msg)
  : msg_(msg)
  {}
  Init_Tag_bottom_right top_left(::tag_interface::msg::Tag::_top_left_type arg)
  {
    msg_.top_left = std::move(arg);
    return Init_Tag_bottom_right(msg_);
  }

private:
  ::tag_interface::msg::Tag msg_;
};

class Init_Tag_top_right
{
public:
  explicit Init_Tag_top_right(::tag_interface::msg::Tag & msg)
  : msg_(msg)
  {}
  Init_Tag_top_left top_right(::tag_interface::msg::Tag::_top_right_type arg)
  {
    msg_.top_right = std::move(arg);
    return Init_Tag_top_left(msg_);
  }

private:
  ::tag_interface::msg::Tag msg_;
};

class Init_Tag_id
{
public:
  Init_Tag_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tag_top_right id(::tag_interface::msg::Tag::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Tag_top_right(msg_);
  }

private:
  ::tag_interface::msg::Tag msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tag_interface::msg::Tag>()
{
  return tag_interface::msg::builder::Init_Tag_id();
}

}  // namespace tag_interface

#endif  // TAG_INTERFACE__MSG__DETAIL__TAG__BUILDER_HPP_

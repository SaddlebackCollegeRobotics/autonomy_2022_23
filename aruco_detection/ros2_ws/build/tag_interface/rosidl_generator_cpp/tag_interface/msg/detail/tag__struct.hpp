// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tag_interface:msg/Tag.idl
// generated code does not contain a copyright notice

#ifndef TAG_INTERFACE__MSG__DETAIL__TAG__STRUCT_HPP_
#define TAG_INTERFACE__MSG__DETAIL__TAG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'top_right'
// Member 'top_left'
// Member 'bottom_right'
// Member 'bottom_left'
#include "tag_interface/msg/detail/coordinate__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tag_interface__msg__Tag __attribute__((deprecated))
#else
# define DEPRECATED__tag_interface__msg__Tag __declspec(deprecated)
#endif

namespace tag_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Tag_
{
  using Type = Tag_<ContainerAllocator>;

  explicit Tag_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Tag_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _id_type =
    std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>>;
  _id_type id;
  using _top_right_type =
    std::vector<tag_interface::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tag_interface::msg::Coordinate_<ContainerAllocator>>>;
  _top_right_type top_right;
  using _top_left_type =
    std::vector<tag_interface::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tag_interface::msg::Coordinate_<ContainerAllocator>>>;
  _top_left_type top_left;
  using _bottom_right_type =
    std::vector<tag_interface::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tag_interface::msg::Coordinate_<ContainerAllocator>>>;
  _bottom_right_type bottom_right;
  using _bottom_left_type =
    std::vector<tag_interface::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tag_interface::msg::Coordinate_<ContainerAllocator>>>;
  _bottom_left_type bottom_left;
  using _position_type =
    std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>>;
  _position_type position;
  using _distance_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__id(
    const std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__top_right(
    const std::vector<tag_interface::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tag_interface::msg::Coordinate_<ContainerAllocator>>> & _arg)
  {
    this->top_right = _arg;
    return *this;
  }
  Type & set__top_left(
    const std::vector<tag_interface::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tag_interface::msg::Coordinate_<ContainerAllocator>>> & _arg)
  {
    this->top_left = _arg;
    return *this;
  }
  Type & set__bottom_right(
    const std::vector<tag_interface::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tag_interface::msg::Coordinate_<ContainerAllocator>>> & _arg)
  {
    this->bottom_right = _arg;
    return *this;
  }
  Type & set__bottom_left(
    const std::vector<tag_interface::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tag_interface::msg::Coordinate_<ContainerAllocator>>> & _arg)
  {
    this->bottom_left = _arg;
    return *this;
  }
  Type & set__position(
    const std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__distance(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tag_interface::msg::Tag_<ContainerAllocator> *;
  using ConstRawPtr =
    const tag_interface::msg::Tag_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tag_interface::msg::Tag_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tag_interface::msg::Tag_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tag_interface::msg::Tag_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tag_interface::msg::Tag_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tag_interface::msg::Tag_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tag_interface::msg::Tag_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tag_interface::msg::Tag_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tag_interface::msg::Tag_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tag_interface__msg__Tag
    std::shared_ptr<tag_interface::msg::Tag_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tag_interface__msg__Tag
    std::shared_ptr<tag_interface::msg::Tag_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Tag_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->top_right != other.top_right) {
      return false;
    }
    if (this->top_left != other.top_left) {
      return false;
    }
    if (this->bottom_right != other.bottom_right) {
      return false;
    }
    if (this->bottom_left != other.bottom_left) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const Tag_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Tag_

// alias to use template instance with default allocator
using Tag =
  tag_interface::msg::Tag_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tag_interface

#endif  // TAG_INTERFACE__MSG__DETAIL__TAG__STRUCT_HPP_

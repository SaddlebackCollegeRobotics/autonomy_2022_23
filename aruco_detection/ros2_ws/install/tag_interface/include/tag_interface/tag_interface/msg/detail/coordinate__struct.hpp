// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tag_interface:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef TAG_INTERFACE__MSG__DETAIL__COORDINATE__STRUCT_HPP_
#define TAG_INTERFACE__MSG__DETAIL__COORDINATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tag_interface__msg__Coordinate __attribute__((deprecated))
#else
# define DEPRECATED__tag_interface__msg__Coordinate __declspec(deprecated)
#endif

namespace tag_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Coordinate_
{
  using Type = Coordinate_<ContainerAllocator>;

  explicit Coordinate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->row = 0ll;
      this->col = 0ll;
    }
  }

  explicit Coordinate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->row = 0ll;
      this->col = 0ll;
    }
  }

  // field types and members
  using _row_type =
    int64_t;
  _row_type row;
  using _col_type =
    int64_t;
  _col_type col;

  // setters for named parameter idiom
  Type & set__row(
    const int64_t & _arg)
  {
    this->row = _arg;
    return *this;
  }
  Type & set__col(
    const int64_t & _arg)
  {
    this->col = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tag_interface::msg::Coordinate_<ContainerAllocator> *;
  using ConstRawPtr =
    const tag_interface::msg::Coordinate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tag_interface::msg::Coordinate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tag_interface::msg::Coordinate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tag_interface::msg::Coordinate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tag_interface::msg::Coordinate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tag_interface::msg::Coordinate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tag_interface::msg::Coordinate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tag_interface::msg::Coordinate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tag_interface::msg::Coordinate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tag_interface__msg__Coordinate
    std::shared_ptr<tag_interface::msg::Coordinate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tag_interface__msg__Coordinate
    std::shared_ptr<tag_interface::msg::Coordinate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Coordinate_ & other) const
  {
    if (this->row != other.row) {
      return false;
    }
    if (this->col != other.col) {
      return false;
    }
    return true;
  }
  bool operator!=(const Coordinate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Coordinate_

// alias to use template instance with default allocator
using Coordinate =
  tag_interface::msg::Coordinate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tag_interface

#endif  // TAG_INTERFACE__MSG__DETAIL__COORDINATE__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tag_interface:msg/Tag.idl
// generated code does not contain a copyright notice

#ifndef TAG_INTERFACE__MSG__DETAIL__TAG__TRAITS_HPP_
#define TAG_INTERFACE__MSG__DETAIL__TAG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tag_interface/msg/detail/tag__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'top_right'
// Member 'top_left'
// Member 'bottom_right'
// Member 'bottom_left'
#include "tag_interface/msg/detail/coordinate__traits.hpp"

namespace tag_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Tag & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    if (msg.id.size() == 0) {
      out << "id: []";
    } else {
      out << "id: [";
      size_t pending_items = msg.id.size();
      for (auto item : msg.id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: top_right
  {
    if (msg.top_right.size() == 0) {
      out << "top_right: []";
    } else {
      out << "top_right: [";
      size_t pending_items = msg.top_right.size();
      for (auto item : msg.top_right) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: top_left
  {
    if (msg.top_left.size() == 0) {
      out << "top_left: []";
    } else {
      out << "top_left: [";
      size_t pending_items = msg.top_left.size();
      for (auto item : msg.top_left) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bottom_right
  {
    if (msg.bottom_right.size() == 0) {
      out << "bottom_right: []";
    } else {
      out << "bottom_right: [";
      size_t pending_items = msg.bottom_right.size();
      for (auto item : msg.bottom_right) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bottom_left
  {
    if (msg.bottom_left.size() == 0) {
      out << "bottom_left: []";
    } else {
      out << "bottom_left: [";
      size_t pending_items = msg.bottom_left.size();
      for (auto item : msg.bottom_left) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: position
  {
    if (msg.position.size() == 0) {
      out << "position: []";
    } else {
      out << "position: [";
      size_t pending_items = msg.position.size();
      for (auto item : msg.position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: distance
  {
    if (msg.distance.size() == 0) {
      out << "distance: []";
    } else {
      out << "distance: [";
      size_t pending_items = msg.distance.size();
      for (auto item : msg.distance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tag & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.id.size() == 0) {
      out << "id: []\n";
    } else {
      out << "id:\n";
      for (auto item : msg.id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: top_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.top_right.size() == 0) {
      out << "top_right: []\n";
    } else {
      out << "top_right:\n";
      for (auto item : msg.top_right) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: top_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.top_left.size() == 0) {
      out << "top_left: []\n";
    } else {
      out << "top_left:\n";
      for (auto item : msg.top_left) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: bottom_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bottom_right.size() == 0) {
      out << "bottom_right: []\n";
    } else {
      out << "bottom_right:\n";
      for (auto item : msg.bottom_right) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: bottom_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bottom_left.size() == 0) {
      out << "bottom_left: []\n";
    } else {
      out << "bottom_left:\n";
      for (auto item : msg.bottom_left) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position.size() == 0) {
      out << "position: []\n";
    } else {
      out << "position:\n";
      for (auto item : msg.position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.distance.size() == 0) {
      out << "distance: []\n";
    } else {
      out << "distance:\n";
      for (auto item : msg.distance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tag & msg, bool use_flow_style = false)
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
  const tag_interface::msg::Tag & msg,
  std::ostream & out, size_t indentation = 0)
{
  tag_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tag_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const tag_interface::msg::Tag & msg)
{
  return tag_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tag_interface::msg::Tag>()
{
  return "tag_interface::msg::Tag";
}

template<>
inline const char * name<tag_interface::msg::Tag>()
{
  return "tag_interface/msg/Tag";
}

template<>
struct has_fixed_size<tag_interface::msg::Tag>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tag_interface::msg::Tag>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tag_interface::msg::Tag>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TAG_INTERFACE__MSG__DETAIL__TAG__TRAITS_HPP_

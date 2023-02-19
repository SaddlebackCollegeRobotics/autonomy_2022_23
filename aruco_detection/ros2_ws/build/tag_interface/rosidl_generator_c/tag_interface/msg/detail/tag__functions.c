// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tag_interface:msg/Tag.idl
// generated code does not contain a copyright notice
#include "tag_interface/msg/detail/tag__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `id`
// Member `position`
// Member `distance`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `top_right`
// Member `top_left`
// Member `bottom_right`
// Member `bottom_left`
#include "tag_interface/msg/detail/coordinate__functions.h"

bool
tag_interface__msg__Tag__init(tag_interface__msg__Tag * msg)
{
  if (!msg) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__int64__Sequence__init(&msg->id, 0)) {
    tag_interface__msg__Tag__fini(msg);
    return false;
  }
  // top_right
  if (!tag_interface__msg__Coordinate__Sequence__init(&msg->top_right, 0)) {
    tag_interface__msg__Tag__fini(msg);
    return false;
  }
  // top_left
  if (!tag_interface__msg__Coordinate__Sequence__init(&msg->top_left, 0)) {
    tag_interface__msg__Tag__fini(msg);
    return false;
  }
  // bottom_right
  if (!tag_interface__msg__Coordinate__Sequence__init(&msg->bottom_right, 0)) {
    tag_interface__msg__Tag__fini(msg);
    return false;
  }
  // bottom_left
  if (!tag_interface__msg__Coordinate__Sequence__init(&msg->bottom_left, 0)) {
    tag_interface__msg__Tag__fini(msg);
    return false;
  }
  // position
  if (!rosidl_runtime_c__int64__Sequence__init(&msg->position, 0)) {
    tag_interface__msg__Tag__fini(msg);
    return false;
  }
  // distance
  if (!rosidl_runtime_c__double__Sequence__init(&msg->distance, 0)) {
    tag_interface__msg__Tag__fini(msg);
    return false;
  }
  return true;
}

void
tag_interface__msg__Tag__fini(tag_interface__msg__Tag * msg)
{
  if (!msg) {
    return;
  }
  // id
  rosidl_runtime_c__int64__Sequence__fini(&msg->id);
  // top_right
  tag_interface__msg__Coordinate__Sequence__fini(&msg->top_right);
  // top_left
  tag_interface__msg__Coordinate__Sequence__fini(&msg->top_left);
  // bottom_right
  tag_interface__msg__Coordinate__Sequence__fini(&msg->bottom_right);
  // bottom_left
  tag_interface__msg__Coordinate__Sequence__fini(&msg->bottom_left);
  // position
  rosidl_runtime_c__int64__Sequence__fini(&msg->position);
  // distance
  rosidl_runtime_c__double__Sequence__fini(&msg->distance);
}

bool
tag_interface__msg__Tag__are_equal(const tag_interface__msg__Tag * lhs, const tag_interface__msg__Tag * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__int64__Sequence__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // top_right
  if (!tag_interface__msg__Coordinate__Sequence__are_equal(
      &(lhs->top_right), &(rhs->top_right)))
  {
    return false;
  }
  // top_left
  if (!tag_interface__msg__Coordinate__Sequence__are_equal(
      &(lhs->top_left), &(rhs->top_left)))
  {
    return false;
  }
  // bottom_right
  if (!tag_interface__msg__Coordinate__Sequence__are_equal(
      &(lhs->bottom_right), &(rhs->bottom_right)))
  {
    return false;
  }
  // bottom_left
  if (!tag_interface__msg__Coordinate__Sequence__are_equal(
      &(lhs->bottom_left), &(rhs->bottom_left)))
  {
    return false;
  }
  // position
  if (!rosidl_runtime_c__int64__Sequence__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // distance
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->distance), &(rhs->distance)))
  {
    return false;
  }
  return true;
}

bool
tag_interface__msg__Tag__copy(
  const tag_interface__msg__Tag * input,
  tag_interface__msg__Tag * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__int64__Sequence__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // top_right
  if (!tag_interface__msg__Coordinate__Sequence__copy(
      &(input->top_right), &(output->top_right)))
  {
    return false;
  }
  // top_left
  if (!tag_interface__msg__Coordinate__Sequence__copy(
      &(input->top_left), &(output->top_left)))
  {
    return false;
  }
  // bottom_right
  if (!tag_interface__msg__Coordinate__Sequence__copy(
      &(input->bottom_right), &(output->bottom_right)))
  {
    return false;
  }
  // bottom_left
  if (!tag_interface__msg__Coordinate__Sequence__copy(
      &(input->bottom_left), &(output->bottom_left)))
  {
    return false;
  }
  // position
  if (!rosidl_runtime_c__int64__Sequence__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // distance
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->distance), &(output->distance)))
  {
    return false;
  }
  return true;
}

tag_interface__msg__Tag *
tag_interface__msg__Tag__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tag_interface__msg__Tag * msg = (tag_interface__msg__Tag *)allocator.allocate(sizeof(tag_interface__msg__Tag), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tag_interface__msg__Tag));
  bool success = tag_interface__msg__Tag__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tag_interface__msg__Tag__destroy(tag_interface__msg__Tag * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tag_interface__msg__Tag__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tag_interface__msg__Tag__Sequence__init(tag_interface__msg__Tag__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tag_interface__msg__Tag * data = NULL;

  if (size) {
    data = (tag_interface__msg__Tag *)allocator.zero_allocate(size, sizeof(tag_interface__msg__Tag), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tag_interface__msg__Tag__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tag_interface__msg__Tag__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tag_interface__msg__Tag__Sequence__fini(tag_interface__msg__Tag__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tag_interface__msg__Tag__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tag_interface__msg__Tag__Sequence *
tag_interface__msg__Tag__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tag_interface__msg__Tag__Sequence * array = (tag_interface__msg__Tag__Sequence *)allocator.allocate(sizeof(tag_interface__msg__Tag__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tag_interface__msg__Tag__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tag_interface__msg__Tag__Sequence__destroy(tag_interface__msg__Tag__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tag_interface__msg__Tag__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tag_interface__msg__Tag__Sequence__are_equal(const tag_interface__msg__Tag__Sequence * lhs, const tag_interface__msg__Tag__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tag_interface__msg__Tag__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tag_interface__msg__Tag__Sequence__copy(
  const tag_interface__msg__Tag__Sequence * input,
  tag_interface__msg__Tag__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tag_interface__msg__Tag);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tag_interface__msg__Tag * data =
      (tag_interface__msg__Tag *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tag_interface__msg__Tag__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tag_interface__msg__Tag__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tag_interface__msg__Tag__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

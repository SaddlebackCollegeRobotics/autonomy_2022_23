#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tag_interface::tag_interface__rosidl_generator_py" for configuration ""
set_property(TARGET tag_interface::tag_interface__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(tag_interface::tag_interface__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libtag_interface__rosidl_generator_py.so"
  IMPORTED_SONAME_NOCONFIG "libtag_interface__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS tag_interface::tag_interface__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_tag_interface::tag_interface__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libtag_interface__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

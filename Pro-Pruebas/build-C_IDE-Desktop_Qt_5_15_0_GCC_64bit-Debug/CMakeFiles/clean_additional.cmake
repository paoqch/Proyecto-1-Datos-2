# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/C_IDE_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/C_IDE_autogen.dir/ParseCache.txt"
  "C_IDE_autogen"
  )
endif()

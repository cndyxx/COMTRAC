# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appcomtrac_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appcomtrac_autogen.dir\\ParseCache.txt"
  "appcomtrac_autogen"
  )
endif()

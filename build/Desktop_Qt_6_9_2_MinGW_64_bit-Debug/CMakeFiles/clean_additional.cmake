# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MyMainApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MyMainApp_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\MyTests_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MyTests_autogen.dir\\ParseCache.txt"
  "MyMainApp_autogen"
  "MyTests_autogen"
  )
endif()

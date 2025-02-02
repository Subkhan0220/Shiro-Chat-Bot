# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SHIROOO_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SHIROOO_autogen.dir\\ParseCache.txt"
  "SHIROOO_autogen"
  )
endif()

﻿# CMakeList.txt : CMake project for PIMPL_all, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory ("DivideConquer")
add_subdirectory ("General")
add_subdirectory ("Greedy")
# Add source to this project's executable.
file(GLOB_RECURSE GLOB_SOURCE "*.cpp")
SET(SOURCES ${GLOB_SOURCE})

file(GLOB_RECURSE GLOB_HEADER "*.h")
set(HEADER_FILES ${GLOB_HEADER})

add_executable (Algorithms ${SOURCES} ${HEADERS})

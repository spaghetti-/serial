cmake_minimum_required(VERSION 3.2.0 FATAL_ERROR)
project(serial)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(SERIAL_VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
find_package(Boost REQUIRED COMPONENTS system thread)
set(Boost_USE_STATIC_LIBS ON)
set(Boost USE_MULTITHREADED ON)
include_directories(
  include
  ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
add_library(serial SHARED src/serial.cpp)
target_link_libraries(serial 
  ${Boost_LIBRARIES})


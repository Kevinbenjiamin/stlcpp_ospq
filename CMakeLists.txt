cmake_minimum_required(VERSION 3.10.0)
project(stlcpp_osqp VERSION 0.1.0 LANGUAGES C CXX)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


add_executable(stlcpp_osqp main.cpp)

add_subdirectory(stl_cpp)
add_subdirectory(osqp_demo)
cmake_minimum_required(VERSION 3.10.0)
project(stl_cpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(stlcpp main.cpp src/speechManager.cpp src/Speaker.cpp)

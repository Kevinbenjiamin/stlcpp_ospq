cmake_minimum_required(VERSION 3.10.0)
project(osqp_demo VERSION 0.1.0 LANGUAGES C CXX)

find_package(OsqpEigen REQUIRED)
add_executable(osqp_demo osqp_demo.cpp)
target_link_libraries(osqp_demo PRIVATE OsqpEigen::OsqpEigen)

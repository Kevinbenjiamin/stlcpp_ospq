cmake_minimum_required(VERSION 3.10.0)
project(osqp_demo VERSION 0.1.0 LANGUAGES C CXX)

# include_directories(/usr/local/include)
# link_directories(/usr/local/lib)

include_directories(/usr/include/cppad)


add_executable(CppAD_demo CppAD_demo.cpp)


add_executable(cppad_ipopt_demo cppad_ipopt_demo.cpp)
target_link_libraries(cppad_ipopt_demo ipopt)

find_package(OsqpEigen REQUIRED)
add_executable(osqp_demo osqp_demo.cpp)
target_link_libraries(osqp_demo PRIVATE OsqpEigen::OsqpEigen)

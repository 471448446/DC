cmake_minimum_required(VERSION 3.15)
project(Hello C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC_FILES "cpp/hello/*.c*")
add_executable(hello_c ${SRC_FILES})
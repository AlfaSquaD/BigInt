cmake_minimum_required(VERSION 3.16)
project(BigInt C)

set(CMAKE_C_STANDARD 99)

enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE src ${PROJECT_SOURCE_DIR}/src/*.c)

add_subdirectory(tests)

add_library(BigInt ${src})


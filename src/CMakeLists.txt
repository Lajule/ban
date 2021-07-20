cmake_minimum_required(VERSION 3.1)
project(ban C)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(ban ban.c)

cmake_minimum_required(VERSION 3.20)
project(kakimasu VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Werror -Wextra -Wold-style-cast -pedantic)

include_directories(include src)

add_library(kakimasu SHARED)

add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(tests)
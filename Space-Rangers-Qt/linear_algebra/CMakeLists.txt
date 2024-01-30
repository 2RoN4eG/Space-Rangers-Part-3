cmake_minimum_required(VERSION 3.14)

project(linear_algebra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(linear_algebra SHARED
    linear_algebra_global.h
    t_linear_algebra.h t_linear_algebra.cpp
    t_2d_vector.h t_2d_vector.cpp
    t_2d_position.h t_2d_position.cpp
    t_2d_container.h t_2d_container.cpp
    t_2d_vector_systems.h t_2d_vector_systems.cpp
    t_2d_position_systems.h t_2d_position_systems.cpp

)

target_compile_definitions(linear_algebra PRIVATE linear_algebra_LIBRARY)

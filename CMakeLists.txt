cmake_minimum_required(VERSION 3.0)

project(http_header)

set(${CMAKE_BUILD_TYPE} "debug")


include_directories(./include)
aux_source_directory(src include_src)

set(main_name main.cpp)

add_executable(main ${main_name} ${include_src})

add_compile_options(-std=c++11)




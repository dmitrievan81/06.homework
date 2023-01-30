cmake_minimum_required(VERSION 3.10)

project(example_list)

message("---! CMAKE_CURRENT_BINARYDIR=${CMAKE_CURRENT_BINARY_DIR}")

add_executable(
    example_list
    main.cpp
)

set_target_properties(
    example_list PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
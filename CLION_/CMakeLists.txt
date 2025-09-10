cmake_minimum_required(VERSION 3.25)
project(CLION_)

set(CMAKE_CXX_STANDARD 17)

# Define two separate executables
add_executable(hashing hashing.cpp)
add_executable(sorting sorting.cpp
        recursiveBubble.cpp)

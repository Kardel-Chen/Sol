cmake_minimum_required(VERSION 3.19)
project(Sol)

set(CMAKE_CXX_STANDARD 14)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/testingCases.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(Sol main.cpp Solution.cpp Solution.h Result.cpp Result.h)
cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        cmake-build-debug/car.cpp
        cmake-build-debug/car.h
        cmake-build-debug/person.cpp
        cmake-build-debug/person.h
        cmake-build-debug/book.cpp
        cmake-build-debug/book.h)

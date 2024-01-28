cmake_minimum_required(VERSION 3.27)
project(Library)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Library
        src/BookEntry.cpp
        headers/BookEntry.h
        headers/Genre.h
        src/main.cpp
        src/Genre.cpp
        src/CSVHandler.cpp
        headers/CSVHandler.h
        src/Library.cpp
        headers/Library.h)

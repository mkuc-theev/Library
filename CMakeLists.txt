cmake_minimum_required(VERSION 3.27)
project(Library)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Library
        Book.cpp
        Book.h
        BookRepository.cpp
        BookRepository.h
        Genre.h
        main.cpp
        Genre.cpp
        CSVHandler.cpp
        CSVHandler.h
        Library.cpp
        Library.h)

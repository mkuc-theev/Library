cmake_minimum_required(VERSION 3.27)
project(Library)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
include_directories(.)

add_executable(Library
        src/BookEntry.cpp
        headers/BookEntry.h
        headers/Genre.h
        src/main.cpp
        src/Genre.cpp
        src/CSVHandler.cpp
        headers/CSVHandler.h
        src/BookRepository.cpp
        headers/BookRepository.h
        headers/MenuHandler.h
        src/ProgramSettings.cpp
        headers/ProgramSettings.h
        src/MenuHandler.cpp
        src/Application.cpp
        headers/Application.h)

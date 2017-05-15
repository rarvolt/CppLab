cmake_minimum_required(VERSION 3.7)
project(cpp_lab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Data.cpp Data.h Pracownik.cpp Pracownik.h Nauczyciel.cpp Nauczyciel.h Szkola.cpp Szkola.h)
add_executable(cpp_lab ${SOURCE_FILES})
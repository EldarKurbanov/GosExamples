cmake_minimum_required(VERSION 3.16)
project(GosExamples)

set(CMAKE_CXX_STANDARD 20)

add_executable(GosExamples main.cpp Polynom.cpp Polynom.hpp Complex.cpp Complex.hpp Point.cpp Point.hpp Users.cpp Users.hpp)
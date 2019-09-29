cmake_minimum_required(VERSION 3.15)
project(app_security)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(AppSecAssignment1)

add_executable(app_security
        AppSecAssignment1/dictionary.c
        AppSecAssignment1/dictionary.h
        AppSecAssignment1/Makefile
        AppSecAssignment1/test_main.c
        functiontest/main.c
        valgrind/valgrindtest.c
        dictionary.c
        dictionary.h
        spell.c
        sum.c
        test_main.c)

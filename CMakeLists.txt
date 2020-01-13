cmake_minimum_required(VERSION 3.15)
project(DrWeb_test_task)

set(PROJECT_NAME DrWeb_test_task)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

include_directories(src)
include_directories(src/dictionary)
include_directories(src/notFoundException)
include_directories(test)

add_subdirectory(test)

add_executable(${PROJECT_NAME}
        src/dictionary/dictionary.h
        src/dictionary/dictionary_interface.h
        src/notFoundException/notFoundException.h
        src/notFoundException/notFoundException_interface.h
        src/main.cpp)

cmake_minimum_required(VERSION 3.15)
project(Tests)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME Tests)

set(SOURCES
    test.cpp
)

add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(google_tests_run ${SOURCES})

target_link_libraries(google_tests_run gtest gtest_main)
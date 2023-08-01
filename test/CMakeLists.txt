cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

link_libraries(ft GTest::gtest GTest::gtest_main)

file(GLOB ARGS_SOURCES ${CMAKE_SOURCE_DIR}/src/args/*.c ${CMAKE_SOURCE_DIR}/src/error/*.c)
add_executable(args_test args_test.cpp ${ARGS_SOURCES})

file(GLOB DEQUE_SOURCES ${CMAKE_SOURCE_DIR}/src/deque/*.c)
add_executable(deque_test deque_test.cpp ${DEQUE_SOURCES})

add_executable(quick_select_test quick_select_test.cpp ${CMAKE_SOURCE_DIR}/src/algorithm/quick_select.c)
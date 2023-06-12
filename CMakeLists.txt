cmake_minimum_required(VERSION 3.25)
project(push_swap C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

add_subdirectory(libft)

file(GLOB SOURCES src/*.c src/**/*.c)

add_executable(push_swap ${SOURCES})
target_link_libraries(push_swap ft)
target_include_directories(push_swap PRIVATE src)
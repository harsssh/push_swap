cmake_minimum_required(VERSION 3.25)
project(push_swap C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

include_directories(libft src)

file(GLOB LIBFT libft/*.c libft/**/*.c)
file(GLOB SOURCES src/*.c src/**/*.c)

add_library(ft STATIC ${LIBFT})

add_executable(push_swap ${SOURCES})
target_link_libraries(push_swap ft)
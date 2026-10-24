cmake_minimum_required(VERSION 4.4.3)

project(CHIP8 C)

set (SOURCE_FILES
    src/main.c
    src/chip8.c
)

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
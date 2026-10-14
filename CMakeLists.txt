cmake_minimum_required(VERSION 4.4.3)

project(CHIP8 C)

set (SOURCE_FILES
    src/main.c
)

#include_directories(include) Si quiero añadir una carpeta con includes

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
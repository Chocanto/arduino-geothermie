cmake_minimum_required(VERSION 2.6)

project(ArduinoGeothermie)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

file(
    GLOB_RECURSE
    source_files
    src/*
)

add_executable(
    arduino
    ${source_files}
)


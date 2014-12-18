cmake_minimum_required(VERSION 2.6)

project(ServerGeothermie)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

file(
    GLOB_RECURSE
    source_files
    src/*
)

add_executable(
    server
    ${source_files}
)


cmake_minimum_required(VERSION 2.8)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/CMakeModules/ArduinoToolchain.cmake)

project(ArduinoGeothermie C CXX)

print_board_list()
print_programmer_list()

file(
    GLOB
    source_files
    src/*.cpp
)

file(
    GLOB
    header_files
    src/*.h
)


# libraries
set(StandardCplusplus_RECURSE True)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs)

# firmware params
set(geothermie_BOARD ethernet)
set(geothermie_PORT /dev/tty.usbserial-A6024Z1X)
set(geothermie_SRCS 
    ${source_files}
)
set(geothermie_HDRS 
    ${header_files}
)

generate_arduino_firmware(geothermie)

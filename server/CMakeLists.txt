cmake_minimum_required(VERSION 2.6)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMakeModules)

project(ServerGeothermie)

set(LIBS "")

FIND_PACKAGE(MySQLConnectorCPP REQUIRED)
if (MYSQLCONNECTORCPP_FOUND)
    include_directories(${MYSQLCONNECTORCPP_INCLUDE_DIRS})  
    link_directories(${MYSQLCONNECTORCPP_LIBRARIES})
    set(LIBS ${LIBS} ${MYSQLCONNECTORCPP_LIBRARIES})
else()
    message(FATAL_ERROR "Cannot continue: Mysql C++ Connector is not found")
endif()

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

file(
    GLOB
    source_files
    src/*.cpp
)

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_BINARY_DIR}")
#set(LIBS ${LIBS} ${CMAKE_BINARY_DIR})
#message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
add_executable(server ${source_files})

target_link_libraries(server ${LIBS})

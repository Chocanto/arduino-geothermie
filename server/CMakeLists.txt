cmake_minimum_required(VERSION 2.6.2)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMakeModules)
set(ARCHIVE_OUTPUT_DIRECTORY lib/)

project(ServerGeothermie CXX C)

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

include_directories("${CMAKE_SOURCE_DIR}/src")


add_library (server4tests STATIC ${source_files})
set_property(TARGET server4tests PROPERTY ARCHIVE_OUTPUT_DIRECTORY lib/)
target_link_libraries(server4tests ${LIBS})

add_executable(server ${source_files})
target_link_libraries(server ${LIBS})

add_subdirectory(test)

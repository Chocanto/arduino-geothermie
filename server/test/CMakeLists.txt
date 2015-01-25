if (COMMAND set_up_hermetic_build)
    set_up_hermetic_build()
endif()

include(CMakeUtils/internal_utils.cmake)
config_compiler_and_linker()

FIND_PACKAGE(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})  
    set(LIBS ${LIBS} ${GTEST_BOTH_LIBRARIES})
    set(LIBS ${LIBS} ${GTEST_MAIN_LIBRARY})
else()
    message(FATAL_ERROR "Cannot continue: Google Test is not found")
endif()

enable_testing()

add_executable(test_mysql TestMysql.cpp)

target_link_libraries(test_mysql ${LIBS} pthread server4tests)

add_test(test_mysql bin/test_mysql)

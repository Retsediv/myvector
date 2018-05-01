cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME_STR myvector)
project(${PROJECT_NAME_STR} C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -Wall")

find_package(Threads REQUIRED)

#-------------------
# Test
#-------------------
enable_testing()
include_directories(${COMMON_INCLUDES})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/src/*.cpp)

add_executable(runAllTests ${TEST_SRC_FILES})
target_link_libraries(runAllTests gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})

#-----------------
# Main user program
#-----------------
add_executable(myvector main.cpp myvector.hpp exceptions.h)
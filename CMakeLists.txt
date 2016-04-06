cmake_minimum_required(VERSION 2.8.11)

project(matcher)
set(PROJECT_VERSION 0.0.2)

option(UNITTEST "Build unit tests" ON)
option(UNITTEST_VERBOSE "Verbose unit test output" OFF)

message(STATUS "~~ ${PROJECT_NAME} ${PROJECT_VERSION} ~~")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include_directories("include")

add_definitions(-std=c++11 -Wall -Wextra -Werror -pedantic -Wshadow)

if( UNITTEST )
    enable_testing()
    subdirs(test)
endif()


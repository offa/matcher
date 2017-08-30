cmake_minimum_required(VERSION 3.2)

project(matcher)
set(PROJECT_VERSION 0.0.4)

option(UNITTEST "Build unit tests" ON)
option(UNITTEST_VERBOSE "Verbose unit test output" OFF)

message(STATUS "~~ ${PROJECT_NAME} ${PROJECT_VERSION} ~~")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_compile_options(-Wall
                    -Wextra
                    -Werror
                    -pedantic
                    -Wshadow
                    -Wold-style-cast
                    )

include_directories("include")


if( UNITTEST )
    enable_testing()
    subdirs(test)
endif()


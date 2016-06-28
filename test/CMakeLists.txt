message(STATUS "Building Unit Tests ${UNITTEST}")

find_package(CppUTest REQUIRED)

add_library(testmain OBJECT TestMain.cpp)
target_include_directories(testmain SYSTEM PUBLIC
                            ${CppUTest_INCLUDE_DIR}
                            ${CppUTest_Ext_INCLUDE_DIR}
                            )


macro(_add_test _NAME _SRC)
    add_executable(${_NAME} ${${_SRC}} $<TARGET_OBJECTS:testmain>)
    add_test(NAME ${_NAME} COMMAND ${_NAME})

    target_include_directories(${_NAME} PUBLIC
                                ${CppUTest_INCLUDE_DIR}
                                ${CppUTest_Ext_INCLUDE_DIR}
                                )
    target_link_libraries(${_NAME} ${CppUTest_LIBRARY})
endmacro()


list(APPEND TEST_SRC ActualTest.cpp
                    CombinationMatcherTest.cpp
                    CompareMatcherTest.cpp
                    ContainerMatcherTest.cpp
                    DoubleMatcherTest.cpp
                    StringMatcherTest.cpp
                    MatchResultTest.cpp
                    )
_add_test("AllTests" TEST_SRC)


set(TEST_FLAGS -c)

if( UNITTEST_VERBOSE )
    set(TEST_FLAGS ${TEST_FLAGS} -v)
endif()

add_custom_target(unittest AllTests ${TEST_FLAGS}
                        COMMENT "Running unittests\n\n"
                        VERBATIM
                        )



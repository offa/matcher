message(STATUS "Building Unit Tests ${UNITTEST}")

find_package(CppUTest REQUIRED)

add_library(testmain OBJECT TestMain.cpp)
target_include_directories(testmain SYSTEM PUBLIC
                            ${CppUTest_INCLUDE_DIR}
                            ${CppUTest_Ext_INCLUDE_DIR}
                            )


function(add_test_suite name src)
    add_executable(${name} ${${src}} $<TARGET_OBJECTS:testmain>)
    add_test(NAME ${name} COMMAND ${name})

    target_include_directories(${name} SYSTEM PUBLIC
                                ${CppUTest_INCLUDE_DIR}
                                ${CppUTest_Ext_INCLUDE_DIR}
                                )
    target_link_libraries(${name} ${CppUTest_LIBRARY})
endfunction()


list(APPEND TEST_SRC ActualTest.cpp
                    CombinationMatcherTest.cpp
                    CompareMatcherTest.cpp
                    ContainerMatcherTest.cpp
                    DoubleMatcherTest.cpp
                    StringMatcherTest.cpp
                    MatchResultTest.cpp
                    )
add_test_suite(AllTests TEST_SRC)


set(TEST_FLAGS -c)

if( UNITTEST_VERBOSE )
    set(TEST_FLAGS ${TEST_FLAGS} -v)
endif()

add_custom_target(unittest AllTests ${TEST_FLAGS}
                        COMMENT "Running unittests\n\n"
                        VERBATIM
                        )



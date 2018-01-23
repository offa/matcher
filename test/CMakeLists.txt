find_package(CppUTest REQUIRED)

add_library(testmain TestMain.cpp)
target_link_libraries(testmain PUBLIC CppUTest::CppUTest CppUTest::Mock)


function(add_test_suite name src)
    add_executable(${name} ${${src}})
    add_test(NAME ${name} COMMAND ${name})

    target_link_libraries(${name} testmain)
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



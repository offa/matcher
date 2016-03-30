message(STATUS "Building Unit Tests ${UNITTEST}")

find_package(CppUTest REQUIRED)

add_library(testmain OBJECT TestMain.cpp)
target_include_directories(testmain PUBLIC
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
                    FloatMatcherTest.cpp
                    StringMatcherTest.cpp
                    )
_add_test("AllTests" TEST_SRC)

add_custom_target(unittest AllTests
                        COMMENT "Running unittests\n\n"
                        VERBATIM
                        )



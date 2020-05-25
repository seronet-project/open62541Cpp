cmake_minimum_required(VERSION 3.5)
project(Open62541Cpp_Tests)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

# NO_CMAKE_SYSTEM_PACKAGE_REGISTRY prevents the usage of 'FindGTest.cmake' from the cmake
# installation. As this does not include GMock.
find_package(GTest REQUIRED NO_CMAKE_SYSTEM_PACKAGE_REGISTRY)

add_executable(Test_UA_QualifiedName Test_UA_QualifiedName.cpp)
target_link_libraries(Test_UA_QualifiedName Open62541Cpp GTest::gtest_main)
add_test(NAME QualifiedName COMMAND Test_UA_QualifiedName)
set_tests_properties(QualifiedName PROPERTIES TIMEOUT 20)

add_executable(Test_UA_RelativPathElement Test_UA_RelativPathElement.cpp)
target_link_libraries(Test_UA_RelativPathElement Open62541Cpp GTest::gtest_main)
add_test(NAME RelativPathElement COMMAND Test_UA_RelativPathElement)
set_tests_properties(RelativPathElement PROPERTIES TIMEOUT 20)

#include <gtest/gtest.h>

#include <Open62541Cpp/UA_RelativPathElement.hpp>

// Memory leak test
TEST(RelativPathElement, CreateDetroy)
{
    open62541Cpp::UA_RelativPathElement obj1(1, "dasd");
    open62541Cpp::UA_RelativPathElement obj2;
    open62541Cpp::UA_RelativPathElement obj3(obj1);
}

TEST(RelativPathElement, Assign)
{
    open62541Cpp::UA_RelativPathElement obj1(1, "dasd");
    open62541Cpp::UA_RelativPathElement obj2;
    obj2 = obj1;
    open62541Cpp::UA_RelativPathElement obj3 = obj1;
}


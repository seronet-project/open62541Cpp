#include <gtest/gtest.h>

#include <Open62541Cpp/UA_RelativPathElement.hpp>

// Memory leak test
TEST(RelativPathElement, CreateDestroy)
{
    open62541Cpp::UA_RelativPathElement obj1(1, "test");
    open62541Cpp::UA_RelativPathElement obj2;
    open62541Cpp::UA_RelativPathElement obj3(obj1);
}

TEST(RelativPathElement, Assign)
{
    open62541Cpp::UA_RelativPathElement obj1(1, "test");
    open62541Cpp::UA_RelativPathElement obj2;
    obj2 = obj1;
    open62541Cpp::UA_RelativPathElement obj3 = obj1;
}

TEST(RelativPathElement, AssignNotNullToNull)
{
    open62541Cpp::UA_RelativPathElement obj1(1, "test");
    open62541Cpp::UA_RelativPathElement obj2;
    obj1 = obj2;
}

TEST(RelativPathElement, AssignNotNullToNotNull)
{
    open62541Cpp::UA_RelativPathElement obj1(1, "test");
    open62541Cpp::UA_RelativPathElement obj2(2, "test2");
    obj1 = obj2;

}

TEST(RelativPathElement, AssignNullToNull)
{
    open62541Cpp::UA_RelativPathElement obj1;
    open62541Cpp::UA_RelativPathElement obj2;
    obj1 = obj2;
}

TEST(RelativPathElement, AssignNullToNotNull)
{
    open62541Cpp::UA_RelativPathElement obj1(1, "test");
    open62541Cpp::UA_RelativPathElement obj2;
    obj1 = obj2;
}

TEST(RelativPathElement, SelfAssignNotNull)
{
    open62541Cpp::UA_RelativPathElement obj1(1, "test");
    obj1 = obj1;
}

TEST(RelativPathElement, SelfAssignNull)
{
    open62541Cpp::UA_RelativPathElement obj1;
    obj1 = obj1;
}
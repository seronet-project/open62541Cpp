#include <gtest/gtest.h>

#include <Open62541Cpp/UA_QualifiedName.hpp>
#include <open62541/types_generated_handling.h>

open62541Cpp::UA_QualifiedName getQualName(int i)
{
    open62541Cpp::UA_QualifiedName ret(2,"");
    UA_QualifiedName_clear(ret.QualifiedName);
    *ret.QualifiedName = UA_QUALIFIEDNAME_ALLOC(i, "Another");
    return ret;
}

// Testing memory leaks
TEST(QualifiedName, CreateDestroy)
{
    open62541Cpp::UA_QualifiedName obj1(2, "");
    ::UA_QualifiedName QualName = UA_QUALIFIEDNAME_ALLOC(4,"::Value");
    open62541Cpp::UA_QualifiedName obj2(&QualName);
    UA_QualifiedName_clear(&QualName);
}

// Testing memory leaks
TEST(QualifiedName, CopyAssign)
{
    open62541Cpp::UA_QualifiedName obj1(2, "");
    open62541Cpp::UA_QualifiedName obj2 = obj1;
    auto obj3 = obj1;
    auto obj4 = getQualName(3);
}

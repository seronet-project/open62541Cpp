///
/// \file UA_QualifiedName.cpp
/// \author Christian von Arnim
/// \date 11.02.2020
///

#include "UA_QualifiedName.hpp"
#include <open62541/types_generated_handling.h>
#include <sstream>
#include "UA_String.hpp"

namespace open62541Cpp
{

UA_QualifiedName::~UA_QualifiedName()
{
  UA_QualifiedName_delete(QualifiedName);
}

UA_QualifiedName::UA_QualifiedName(UA_UInt16 nsIndex, const std::string &name)
{
  QualifiedName = UA_QualifiedName_new();
  UA_QualifiedName_init(QualifiedName);
  *QualifiedName = UA_QUALIFIEDNAME_ALLOC(nsIndex, name.c_str());
}

UA_QualifiedName::UA_QualifiedName(::UA_QualifiedName *pQualifiedName)
{
  QualifiedName = UA_QualifiedName_new();
  UA_copy(pQualifiedName, QualifiedName, &UA_TYPES[UA_TYPES_QUALIFIEDNAME]);
}

UA_QualifiedName::UA_QualifiedName(const UA_QualifiedName &other) : UA_QualifiedName(other.QualifiedName)
{
}

UA_QualifiedName::operator std::string() const
{

  if (QualifiedName == nullptr)
  {
    return "QualifiedName(nullptr)";
  }

  std::stringstream ss;
  ss << "QualifiedName("
     << QualifiedName->namespaceIndex
     << ", '" << static_cast<std::string>(open62541Cpp::UA_String(&QualifiedName->name)) << "')";

  return ss.str();
}

} // namespace open62541Cpp

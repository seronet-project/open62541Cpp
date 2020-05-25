///
/// \file UA_QualifiedName.hpp
/// \author Christian von Arnim
/// \date 11.02.2020
///

#pragma once
#include <open62541/types.h>
#include <string>

namespace open62541Cpp {

class UA_QualifiedName {

 public:
  ~UA_QualifiedName();
  UA_QualifiedName(UA_UInt16 nsIndex, const std::string &name);

  // Do a copy
  explicit UA_QualifiedName(::UA_QualifiedName *pQualifiedName);
  UA_QualifiedName(const UA_QualifiedName &other);
  UA_QualifiedName(UA_QualifiedName && other);

  ::UA_QualifiedName *QualifiedName = nullptr;

  UA_QualifiedName &operator=(const UA_QualifiedName &other);
  UA_QualifiedName &operator=(UA_QualifiedName &&other);

  operator std::string() const;
};

}

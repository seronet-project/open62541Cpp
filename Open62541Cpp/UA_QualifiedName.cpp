///
/// \file UA_QualifiedName.cpp
/// \author Christian von Arnim
/// \date 11.02.2020
///

#include "UA_QualifiedName.hpp"
#include <open62541/types_generated_handling.h>

namespace open62541Cpp {

UA_QualifiedName::~UA_QualifiedName() {
  UA_QualifiedName_delete(QualifiedName);
}

UA_QualifiedName::UA_QualifiedName(UA_UInt16 nsIndex, const std::string &name) {
  QualifiedName = UA_QualifiedName_new();
  UA_QualifiedName_init(QualifiedName);
  *QualifiedName = UA_QUALIFIEDNAME_ALLOC(nsIndex, name.c_str());
}
}

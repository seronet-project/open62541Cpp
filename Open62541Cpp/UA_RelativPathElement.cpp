///
/// \file RelativPathElement.cpp
/// \author Christian von Arnim
/// \date 14.01.2020
///

#include <open62541/types.h>
#include <open62541/server_config_default.h>
#include "UA_RelativPathElement.hpp"
#include <open62541/types_generated_handling.h>
namespace open62541Cpp {
const UA_NodeId UA_RelativPathElement::HierarchicalReferences{
    .namespaceIndex = 0,
    .identifierType=UA_NODEIDTYPE_NUMERIC,
    .identifier = {.numeric = UA_NS0ID_HIERARCHICALREFERENCES}
};

UA_RelativPathElement::~UA_RelativPathElement() {
  if (RelativePathElement != nullptr) {
    UA_RelativePathElement_deleteMembers(RelativePathElement);
    UA_RelativePathElement_delete(RelativePathElement);
  }
}
UA_RelativPathElement::UA_RelativPathElement(const UA_RelativPathElement &other) {
  RelativePathElement = UA_RelativePathElement_new();
  UA_RelativePathElement_copy(other.RelativePathElement, RelativePathElement);
}
UA_RelativPathElement::UA_RelativPathElement(UA_UInt16 nsIndex,
                                             std::string name,
                                             const ::UA_NodeId referenceTypeId,
                                             bool includeSubtypes,
                                             bool isInverse) {
  RelativePathElement = UA_RelativePathElement_new();

  RelativePathElement->includeSubtypes = includeSubtypes;
  RelativePathElement->isInverse = isInverse;
  UA_NodeId_copy(&referenceTypeId, &RelativePathElement->referenceTypeId);
  UA_String_copy(open62541Cpp::UA_String(name).String, &RelativePathElement->targetName.name);
  RelativePathElement->targetName.namespaceIndex = nsIndex;
}
}
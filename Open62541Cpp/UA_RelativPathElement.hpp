///
/// \file RelativPathElement.hpp
/// \author Christian von Arnim
/// \date 14.01.2020
///

#pragma once
#include <Open62541Cpp/UA_String.hpp>
#include <open62541/types.h>
#include <open62541/types_generated.h>
#include <string>

namespace open62541Cpp
{
class UA_RelativPathElement
{
public:
  UA_RelativPathElement() = default;
  ::UA_RelativePathElement *RelativePathElement = nullptr;
  ~UA_RelativPathElement();

  static const ::UA_NodeId HierarchicalReferences;

  UA_RelativPathElement(const UA_RelativPathElement &other);
  UA_RelativPathElement& operator=(const UA_RelativPathElement& other);

  UA_RelativPathElement(
      UA_UInt16 nsIndex,
      std::string name,
      const ::UA_NodeId referenceTypeId = HierarchicalReferences,
      bool includeSubtypes = true,
      bool isInverse = false);
};
} // namespace open62541Cpp

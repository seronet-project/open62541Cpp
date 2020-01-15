///
/// \file BrowsePath.hpp
/// \author Christian von Arnim
/// \date 14.01.2020
///

#pragma once

#include <open62541/types_generated.h>
#include "UA_RelativPathElement.hpp"
#include <list>

namespace open62541Cpp {
class UA_BrowsePath {
  UA_BrowsePath() = default;
 public:
  ::UA_BrowsePath *BrowsePath = nullptr;

  ~UA_BrowsePath();
  UA_BrowsePath(const UA_BrowsePath &other);
  UA_BrowsePath(const ::UA_NodeId startNodeId, std::list<UA_RelativPathElement> pathElements);

};
}

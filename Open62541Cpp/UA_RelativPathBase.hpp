///
/// \file RelativPathBase.hpp
/// \author Christian von Arnim
/// \date 15.01.2020
///

#pragma once

#include "UA_RelativPathElement.hpp"
#include <list>

namespace open62541Cpp {
class UA_RelativPathBase {
  std::list<UA_RelativPathElement> relElements;

 public:
  UA_RelativPathBase(std::list<UA_RelativPathElement> base = std::list<UA_RelativPathElement>());

  std::list<UA_RelativPathElement> operator()(const UA_RelativPathElement &el) const;
  std::list<UA_RelativPathElement> operator()(const std::list<UA_RelativPathElement> &els) const;
};
}

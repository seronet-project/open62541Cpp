///
/// \file RelativPathBase.cpp
/// \author Christian von Arnim
/// \date 15.01.2020
///

#include "UA_RelativPathBase.hpp"
namespace open62541Cpp {

UA_RelativPathBase::UA_RelativPathBase(std::list<UA_RelativPathElement> base)
    : relElements(base) {

}
std::list<UA_RelativPathElement> UA_RelativPathBase::operator()(const UA_RelativPathElement &el) const {
  auto ret = relElements;
  ret.push_back(el);
  return ret;
}
}

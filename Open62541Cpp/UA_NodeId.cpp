/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/

#include "UA_NodeId.hpp"
#include <open62541/types_generated_handling.h>
#include <open62541/util.h>

bool mem_less(void *p1, std::size_t size1, void *p2, std::size_t size2) {
  if (size1 != size2) {
    return size1 < size2;
  }
  return memcmp(p1, p2, size1) < 0;
}

namespace open62541Cpp {

UA_NodeId::UA_NodeId() : NodeId(UA_NodeId_new()) {
  UA_NodeId_init(NodeId);
}

UA_NodeId::UA_NodeId(const UA_UInt16 nsIndex, const std::string identifier) : UA_NodeId() {
  NodeId->identifierType = UA_NODEIDTYPE_STRING;
  NodeId->namespaceIndex = nsIndex;
  NodeId->identifier.string = UA_STRING_ALLOC(identifier.c_str());
}

UA_NodeId::UA_NodeId(const UA_UInt16 nsIndex, const UA_UInt32 identifier) : UA_NodeId() {
  NodeId->identifierType = UA_NODEIDTYPE_NUMERIC;
  NodeId->namespaceIndex = nsIndex;
  NodeId->identifier.numeric = identifier;
}

UA_NodeId::UA_NodeId(const UA_UInt16 nsIndex, const UA_Guid identifier) : UA_NodeId() {
  NodeId->identifierType = UA_NODEIDTYPE_GUID;
  NodeId->namespaceIndex = nsIndex;
  NodeId->identifier.guid = identifier;
}

UA_NodeId::UA_NodeId(::UA_NodeId *nodeId, bool takeOwnership) {
  if (takeOwnership) {
    NodeId = nodeId;
  } else {
    NodeId = UA_NodeId_new();
    UA_NodeId_init(NodeId);
    UA_NodeId_copy(nodeId, NodeId);
  }
}

UA_NodeId::UA_NodeId(const ::UA_NodeId *nodeId) : UA_NodeId() {
  UA_NodeId_copy(nodeId, NodeId);
}

UA_NodeId::UA_NodeId(const ::UA_NodeId nodeId) : UA_NodeId(&nodeId) {
}

UA_NodeId::UA_NodeId(const UA_NodeId &other) : UA_NodeId(other.NodeId) {
}

UA_NodeId &UA_NodeId::operator=(const ::UA_NodeId &other) {
  UA_NodeId_copy(&other, NodeId);
  return *this;
}

UA_NodeId &UA_NodeId::operator=(const UA_NodeId &other) {
  UA_NodeId_copy(other.NodeId, NodeId);
  return *this;
}

bool UA_NodeId::operator<(const ::UA_NodeId &other) const {
  return UA_NodeId_order(NodeId, &other) == UA_Order::UA_ORDER_LESS;
}

bool UA_NodeId::operator<(const UA_NodeId &other) const {
  return this->operator<(*(other.NodeId));
}


bool UA_NodeId::operator ==(const UA_NodeId &other) const {
  return UA_NodeId_equal(this->NodeId,other.NodeId);
}

UA_NodeId::~UA_NodeId() {
  if(NodeId != nullptr)
  {
    UA_NodeId_clear(NodeId);
    UA_NodeId_delete(NodeId);
  }
}
UA_NodeId::operator std::string() const {
  UA_String strNodeId = UA_STRING_NULL;
  UA_NodeId_print(NodeId, &strNodeId);
  std::string ret (strNodeId.data, strNodeId.data + strNodeId.length);
  UA_String_clear(&strNodeId);
  return ret;
}

UA_NodeId UA_NodeId::FromConstNodeId(const ::UA_NodeId *nodeId) {
  ::UA_NodeId *dst = UA_NodeId_new();
  UA_NodeId_copy(nodeId, dst);
  return UA_NodeId(dst, false);
}

UA_NodeId::UA_NodeId(UA_NodeId &&other) {
  NodeId = other.NodeId;
  other.NodeId = nullptr;
}

std::ostream& operator<< (std::ostream& stream, const UA_NodeId& nodeId)
{
  return (stream << static_cast<std::string>(nodeId));
}

}

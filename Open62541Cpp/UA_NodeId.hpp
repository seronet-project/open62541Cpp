/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#ifndef UA_NODEID_HPP
#define UA_NODEID_HPP

#include "util.hpp"
#include <open62541/types.h>
#include <string>
#include <ostream>

namespace open62541Cpp {

class UA_NodeId {
 public:
  UA_NodeId();

  UA_NodeId(::UA_NodeId *nodeId, bool takeOwnership);
  UA_NodeId(UA_UInt16 nsIndex, std::string identifier);
  UA_NodeId(UA_UInt16 nsIndex, UA_UInt32 identifier);
  UA_NodeId(UA_UInt16 nsIndex, UA_Guid identifier);
  static UA_NodeId FromConstNodeId(const ::UA_NodeId *nodeId);

  /// Do a copy
  explicit UA_NodeId(const ::UA_NodeId *nodeId);
  explicit UA_NodeId(const ::UA_NodeId nodeId);
  UA_NodeId(const UA_NodeId &other);

  // Move constructor
  UA_NodeId(UA_NodeId &&other);

  UA_NodeId &operator=(const ::UA_NodeId &other);
  UA_NodeId &operator=(const UA_NodeId &other);

  //Comparing for mapping as key value
  bool operator<(const ::UA_NodeId &other) const;
  bool operator<(const UA_NodeId &other) const;
  bool operator ==(const UA_NodeId &other) const;

  operator std::string() const;

  virtual ~UA_NodeId();

  ::UA_NodeId *NodeId;

};

std::ostream& operator<< (std::ostream& stream, const UA_NodeId& nodeId);

}

#endif
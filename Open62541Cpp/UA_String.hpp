/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
//  TODO (Sebastian Friedl) Change internal String to std::string

#ifndef UA_STRING_HPP
#define UA_STRING_HPP

#include "util.hpp"
#include <open62541/types.h>
#include <string>

namespace OPEN_65241_CPP_NAMESPACE {

class UA_String {
 public:
  UA_String();

  UA_String(::UA_String *str, bool takeOwnership);
  explicit UA_String(const char *str);
  explicit UA_String(const std::string &str);
  /// Do a copy
  explicit UA_String(const ::UA_String *str);
  UA_String(const UA_String &other);
  ~UA_String();

  ::UA_String *String;
  bool operator==(const UA_String &rhs) const;
  bool operator!=(const UA_String &rhs) const;
  explicit operator std::string() const;
};

// Allow direct output to std::cout
std::ostream &operator<<(std::ostream &os, UA_String const &str);

}

#endif

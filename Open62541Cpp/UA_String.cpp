/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#include "UA_String.hpp"
#include <open62541/types_generated_handling.h>

namespace open62541Cpp {
UA_String::UA_String() {
  String = UA_String_new();
  UA_String_init(String);
}

UA_String::UA_String(::UA_String *str, bool takeOwnership) {
  if (takeOwnership) {
    String = str;
  } else {
    String = UA_String_new();
    UA_String_init(String);
    UA_String_copy(str, String);
  }
}

UA_String::UA_String(const char *str) : UA_String() {
  *String = UA_STRING_ALLOC(str);
}

UA_String::UA_String(const std::string &str) : UA_String(str.c_str()) {
}

UA_String::UA_String(const ::UA_String *str) : UA_String() {
  UA_String_copy(str, String);
}

UA_String::UA_String(const UA_String &other) : UA_String(other.String) {
}

UA_String::~UA_String() {
  UA_String_deleteMembers(String);
  UA_String_delete(String);
}

UA_String::operator std::string() const {
  if (String->data == nullptr) {
    return std::string();
  } else {
    return std::string(String->data, String->data + String->length);
  }
}

bool UA_String::operator==(const UA_String &rhs) const {
  return UA_String_equal(String, rhs.String);
}

bool UA_String::operator!=(const UA_String &rhs) const {
  return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, UA_String const &str) {
  return os << static_cast<std::string>(str);
}
}
/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/

#include "UA_Argument.hpp"
#include <open62541/types_generated_handling.h>

namespace open62541Cpp {
UA_Argument::UA_Argument() {
  argument = ::UA_Argument_new();
  ::UA_Argument_init(argument);
}

UA_Argument::UA_Argument(::UA_Argument *aArgument, bool takeOwnership) {
  if (takeOwnership) {
    argument = aArgument;
  } else {
    argument = ::UA_Argument_new();
    ::UA_Argument_init(argument);
    ::UA_Argument_copy(aArgument, argument);
  }
}

UA_Argument::UA_Argument(const ::UA_Argument *aArgument) : UA_Argument() {
  UA_Argument_copy(aArgument, argument);
}

UA_Argument::UA_Argument(const UA_Argument &other) : UA_Argument(other.argument) {
}

UA_Argument::~UA_Argument() {
  ///TODO ? How does this behave when no members are reserved?
  UA_Argument_deleteMembers(argument);
  UA_Argument_delete(argument);
}
}
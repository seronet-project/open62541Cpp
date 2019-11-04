/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/

#pragma once


#include "util.hpp"
#include <open62541/types.h>
#include <open62541/types_generated.h>

namespace OPEN_65241_CPP_NAMESPACE {

class UA_Argument {
 public:
  UA_Argument();

  UA_Argument(::UA_Argument *aArgument, bool takeOwnership);
  /// Do a copy
  explicit UA_Argument(const ::UA_Argument *aArgument);
  UA_Argument(const UA_Argument &other);
  ~UA_Argument();

  ::UA_Argument *argument;

};

}

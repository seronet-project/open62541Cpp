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

#include "UA_Argument.hpp"

namespace OPEN_65241_CPP_NAMESPACE {
class UA_ArrayOfArgument {
 public:

  /// Initialize an array of size
  UA_ArrayOfArgument();
  explicit UA_ArrayOfArgument(size_t size);
  UA_ArrayOfArgument(const UA_ArrayOfArgument &other);
  UA_ArrayOfArgument(const ::UA_Argument *aArray, const ::size_t aSize);
  UA_ArrayOfArgument(::UA_Argument *aArray, ::size_t VariantSize, bool takeOwership);
  virtual ~UA_ArrayOfArgument();
  ::UA_Argument *arguments;
  ::size_t arraySize;

  open62541::UA_Argument operator[](UA_UInt32 i);
};
}  // end OPEN_62541_CPP_NAMESPACE

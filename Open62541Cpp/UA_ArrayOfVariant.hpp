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

#include "UA_Variant.hpp"

namespace OPEN_65241_CPP_NAMESPACE {
class UA_ArrayOfVariant {
 public:
  UA_ArrayOfVariant();
  /// Initialize an array of size
  UA_ArrayOfVariant(size_t size);
  UA_ArrayOfVariant(const UA_ArrayOfVariant &other);
  UA_ArrayOfVariant(const ::UA_Variant *varray, const ::size_t VariantSize);
  UA_ArrayOfVariant(::UA_Variant *varray, ::size_t VariantSize, bool takeOwership);
  virtual ~UA_ArrayOfVariant();
  ::UA_Variant *Variants;
  ::size_t VariantsSize;

  open62541::UA_Variant operator[](UA_UInt32 i);

};

}

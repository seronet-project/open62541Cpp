/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/

#include "UA_ArrayOfVariant.hpp"
#include "Exceptions/OpcUaErrorException.hpp"

#include <open62541/types_generated_handling.h>

namespace open62541Cpp {

UA_ArrayOfVariant::UA_ArrayOfVariant() : Variants(nullptr), VariantsSize(0) {
}

UA_ArrayOfVariant::UA_ArrayOfVariant(size_t size) : VariantsSize(size) {
  Variants = static_cast<::UA_Variant *>(UA_Array_new(size, &UA_TYPES[UA_TYPES_VARIANT]));
  for (size_t i = 0; i < size; ++i) {
    UA_Variant_init(&Variants[i]);
  }
}

UA_ArrayOfVariant::UA_ArrayOfVariant(const UA_ArrayOfVariant &other) : UA_ArrayOfVariant(other.Variants,
                                                                                         other.VariantsSize) {
}

UA_ArrayOfVariant::UA_ArrayOfVariant(const ::UA_Variant *varray, const ::size_t vSize) : UA_ArrayOfVariant() {
  VariantsSize = vSize;

  UA_StatusCode status = UA_Array_copy(varray, vSize, (void **) &Variants, &UA_TYPES[UA_TYPES_VARIANT]);
  if (status != UA_STATUSCODE_GOOD) throw Exceptions::OpcUaErrorException(status);
}

UA_ArrayOfVariant::UA_ArrayOfVariant(::UA_Variant *varray, ::size_t vSize, bool takeOwership) {
  VariantsSize = vSize;
  if (takeOwership) {
    Variants = varray;
  } else {
    UA_StatusCode status = UA_Array_copy(varray, vSize, (void **) &Variants, &UA_TYPES[UA_TYPES_VARIANT]);
    //if (status != UA_STATUSCODE_GOOD) throw Exceptions::OpcUaErrorException(status);
  }
}

UA_ArrayOfVariant::~UA_ArrayOfVariant() {
  if (Variants != nullptr) {
    UA_Array_delete(Variants, VariantsSize, &UA_TYPES[UA_TYPES_VARIANT]);
  }
}

UA_Variant UA_ArrayOfVariant::operator[](UA_UInt32 i) {
  assert(i >= 0 && i < VariantsSize);

  return open62541Cpp::UA_Variant(&(Variants[i]));
}

}
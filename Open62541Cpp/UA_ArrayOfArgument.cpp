/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/

#include <stdexcept>
#include "UA_ArrayOfArgument.hpp"
#include "Exceptions/OpcUaErrorException.hpp"
#include <open62541/types_generated_handling.h>

namespace OPEN_65241_CPP_NAMESPACE {

UA_ArrayOfArgument::UA_ArrayOfArgument() : arguments(nullptr), arraySize(0) {
}

UA_ArrayOfArgument::UA_ArrayOfArgument(size_t size) : arraySize(size) {
  arguments = static_cast<::UA_Argument *>(UA_Array_new(size, &UA_TYPES[UA_TYPES_ARGUMENT]));
  for (size_t i = 0; i < size; ++i) {
    UA_Argument_init(&arguments[i]);
  }
}

UA_ArrayOfArgument::UA_ArrayOfArgument(const UA_ArrayOfArgument &other) : UA_ArrayOfArgument(other.arguments,
                                                                                             other.arraySize) {
}

UA_ArrayOfArgument::UA_ArrayOfArgument(const ::UA_Argument *aArray, const ::size_t aSize) : UA_ArrayOfArgument() {
  arraySize = aSize;
  UA_StatusCode status = UA_Array_copy(aArray, aSize, (void **) &arguments, &UA_TYPES[UA_TYPES_ARGUMENT]);
  if (status != UA_STATUSCODE_GOOD) throw Exceptions::OpcUaErrorException(status);

}

UA_ArrayOfArgument::UA_ArrayOfArgument(::UA_Argument *aArray, ::size_t aSize, bool takeOwership) {
  arraySize = aSize;
  if (takeOwership) {
    arguments = aArray;
  } else {
    UA_StatusCode status = UA_Array_copy(aArray, aSize, (void **) &arguments, &UA_TYPES[UA_TYPES_ARGUMENT]);
    if (status != UA_STATUSCODE_GOOD) throw Exceptions::OpcUaErrorException(status);
  }
}

UA_ArrayOfArgument::~UA_ArrayOfArgument() {
  if (arguments != nullptr) {
    UA_Array_delete(arguments, arraySize, &UA_TYPES[UA_TYPES_ARGUMENT]);
  }
}

UA_Argument UA_ArrayOfArgument::operator[](UA_UInt32 i) {
  assert(i >= 0 && i < arraySize);

  return open62541::UA_Argument(&(arguments[i]));
}

}
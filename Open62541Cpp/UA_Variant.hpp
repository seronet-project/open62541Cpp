/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/

#ifndef UA_VARIANT_HPP
#define UA_VARIANT_HPP

#include "util.hpp"
#include <open62541/types.h>
#include <open62541/types_generated.h>

namespace open62541Cpp {

class UA_Variant {
 public:
  UA_Variant();

  UA_Variant(::UA_Variant *variant, bool takeOwnership);
  /// Do a copy
  UA_Variant(const ::UA_Variant *variant);
  UA_Variant(const UA_Variant &other);
  ~UA_Variant();

  ::UA_Variant *Variant;

  bool is_a(const ::UA_DataType *type);
  bool is_a(const ::UA_NodeId *typeNodeId);

  //No Copy
  template<typename T>
  T *getDataAs();
};

template<typename T>
inline T *UA_Variant::getDataAs() {
  return static_cast<T *>(Variant->data);
}

template<>
inline ::UA_String *UA_Variant::getDataAs() {
  assert(is_a(&UA_TYPES[UA_TYPES_STRING]));
  return static_cast<::UA_String *>(Variant->data);
}

// Only implement typechecking during Debugging
#ifdef OPEN62541_DEBUG
#define TYPE_CHECKED_GET_DATA_AS(type, UA_TYPE_INDEX) template <> inline type * UA_Variant::getDataAs() {assert(is_a(&UA_TYPES[UA_TYPE_INDEX])); return static_cast<type*>(Variant->data);}

template <>
inline ::UA_String * UA_Variant::getDataAs()
{
    assert(is_a(&UA_TYPES[UA_TYPES_STRING]));
    return static_cast<::UA_String*>(Variant->data);
}

TYPE_CHECKED_GET_DATA_AS(::UA_Int16, UA_TYPES_INT16)
TYPE_CHECKED_GET_DATA_AS(::UA_Int32, UA_TYPES_INT32)
TYPE_CHECKED_GET_DATA_AS(::UA_Int64, UA_TYPES_INT64)

TYPE_CHECKED_GET_DATA_AS(::UA_UInt16, UA_TYPES_UINT16)
TYPE_CHECKED_GET_DATA_AS(::UA_UInt32, UA_TYPES_UINT32)
TYPE_CHECKED_GET_DATA_AS(::UA_UInt64, UA_TYPES_UINT64)

TYPE_CHECKED_GET_DATA_AS(::UA_Float, UA_TYPES_FLOAT)
TYPE_CHECKED_GET_DATA_AS(::UA_Double, UA_TYPES_DOUBLE)
TYPE_CHECKED_GET_DATA_AS(::UA_Byte, UA_TYPES_BYTE)
TYPE_CHECKED_GET_DATA_AS(::UA_SByte, UA_TYPES_SBYTE)

TYPE_CHECKED_GET_DATA_AS(::UA_Variant, UA_TYPES_VARIANT)

#undef TYPE_CHECKED_GET_DATA_AS	
#endif // OPEN62541_DEBUG
}

#endif

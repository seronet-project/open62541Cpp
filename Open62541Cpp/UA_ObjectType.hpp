/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#ifndef UA_OBJECTTYPE_HPP
#define UA_OBJECTTYPE_HPP

#include "util.hpp"
#include <open62541/types.h>
#include "UA_Object.hpp"

namespace open62541Cpp
{
	class UA_ObjectType
	{
	public:
		UA_ObjectType();

		UA_ObjectType(::UA_ObjectTypeAttributes *objAttr, bool takeOwnership);
		/// Do a copy
		UA_ObjectType(const ::UA_ObjectTypeAttributes *objTypeAttr);
		UA_ObjectType(const UA_ObjectType& other);
		virtual ~UA_ObjectType();

		::UA_ObjectTypeAttributes *Attributes;
	};

}

#endif

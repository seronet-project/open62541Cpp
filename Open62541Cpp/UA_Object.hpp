/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#ifndef UA_OBJECT_HPP
#define UA_OBJECT_HPP

#include "util.hpp"
#include <open62541/types.h>
#include <open62541/types_generated.h>


namespace open62541Cpp
{
	///TODO? Rename to ObjectAttributes?
	class UA_Object
	{
	public:
		UA_Object();

		UA_Object(::UA_ObjectAttributes *objAttr, bool takeOwnership);
		/// Do a copy
		UA_Object(const ::UA_ObjectAttributes *objAttr);
		UA_Object(const UA_Object& other);
		virtual ~UA_Object();

		::UA_ObjectAttributes *Attributes;
	};

}

#endif

/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#include "UA_Object.hpp"
#include <open62541/types_generated_handling.h>

namespace open62541Cpp
{

	UA_Object::UA_Object() : Attributes(UA_ObjectAttributes_new())
	{
		UA_ObjectAttributes_init(Attributes);
	}

	UA_Object::UA_Object(::UA_ObjectAttributes * objAttr, bool takeOwnership)
	{
		if (takeOwnership) {
			Attributes = objAttr;
		}
		else {
			Attributes = UA_ObjectAttributes_new();
			UA_ObjectAttributes_init(Attributes);
			UA_ObjectAttributes_copy(objAttr, Attributes);
		}
	}

	UA_Object::UA_Object(const ::UA_ObjectAttributes * objAttr): UA_Object()
	{
		UA_ObjectAttributes_copy(objAttr, Attributes);
	}

	UA_Object::UA_Object(const UA_Object & other): UA_Object(other.Attributes)
	{
	}

	UA_Object::~UA_Object()
	{
		UA_ObjectAttributes_clear(Attributes);
		UA_ObjectAttributes_delete(Attributes);
	}

}

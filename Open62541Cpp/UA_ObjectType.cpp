/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#include "UA_ObjectType.hpp"
#include <open62541/types_generated_handling.h>

namespace open62541Cpp
{

	UA_ObjectType::UA_ObjectType() : Attributes(UA_ObjectTypeAttributes_new())
	{
		UA_ObjectTypeAttributes_init(Attributes);
	}

	UA_ObjectType::UA_ObjectType(::UA_ObjectTypeAttributes * objTypeAttr, bool takeOwnership)
	{
		if (takeOwnership) {
			Attributes = objTypeAttr;
		}
		else {
			Attributes = UA_ObjectTypeAttributes_new();
			UA_ObjectTypeAttributes_init(Attributes);
			UA_ObjectTypeAttributes_copy(objTypeAttr, Attributes);
		}
	}

	UA_ObjectType::UA_ObjectType(const ::UA_ObjectTypeAttributes * objAttr): UA_ObjectType()
	{
		UA_ObjectTypeAttributes_copy(objAttr, Attributes);
	}

	UA_ObjectType::UA_ObjectType(const UA_ObjectType & other): UA_ObjectType(other.Attributes)
	{
	}

	UA_ObjectType::~UA_ObjectType()
	{
		UA_ObjectTypeAttributes_clear(Attributes);
		UA_ObjectTypeAttributes_delete(Attributes);
	}
}

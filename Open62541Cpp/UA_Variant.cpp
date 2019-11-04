/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#include "UA_Variant.hpp"
#include <open62541/types_generated_handling.h>

namespace OPEN_65241_CPP_NAMESPACE
{
	UA_Variant::UA_Variant()
	{
		Variant = UA_Variant_new();
		UA_Variant_init(Variant);
	}

	UA_Variant::UA_Variant(::UA_Variant * variant, bool takeOwnership)
	{
		if (takeOwnership) {
			Variant = variant;
		}
		else {
			Variant = UA_Variant_new();
			UA_Variant_init(Variant);
			UA_Variant_copy(variant, Variant);
		}
	}

	UA_Variant::UA_Variant(const::UA_Variant * variant): UA_Variant()
	{
		UA_Variant_copy(variant, Variant);
	}

	UA_Variant::UA_Variant(const UA_Variant & other) : UA_Variant(other.Variant)
	{
	}

	UA_Variant::~UA_Variant()
	{
		///TODO ? How does this behave when no members are reserved?
		UA_Variant_deleteMembers(Variant);
		UA_Variant_delete(Variant);
	}

	bool UA_Variant::is_a(const::UA_DataType * type)
	{
		return UA_NodeId_equal(&(Variant->type->typeId), &(type->typeId));
	}

	bool UA_Variant::is_a(const::UA_NodeId * typeNodeId)
	{
		return UA_NodeId_equal(&(Variant->type->typeId), typeNodeId);
	}
}
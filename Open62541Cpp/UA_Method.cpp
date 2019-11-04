/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#include "UA_Method.hpp"
#include <open62541/types_generated_handling.h>

namespace OPEN_65241_CPP_NAMESPACE
{

	UA_Method::UA_Method(): Attributes(UA_MethodAttributes_new())
	{
		UA_MethodAttributes_init(Attributes);
	}

	UA_Method::UA_Method(::UA_MethodAttributes * methodAttr, bool takeOwnership)
	{
		if (takeOwnership)
		{
			Attributes = methodAttr;
		}
		else
		{
			Attributes = UA_MethodAttributes_new();
			UA_MethodAttributes_init(Attributes);
			UA_MethodAttributes_copy(methodAttr, Attributes);
		}
	}

	UA_Method::UA_Method(const::UA_MethodAttributes * methodAttr): UA_Method()
	{
		UA_MethodAttributes_copy(methodAttr, Attributes);
	}

	UA_Method::UA_Method(const UA_Method & other): UA_Method(other.Attributes)
	{
		for (::UA_Argument arg : other.InputArguments) {
			::UA_Argument ar;
			UA_Argument_init(&ar);
			UA_Argument_copy(&arg, &ar);
			InputArguments.push_back(ar);
		}

		for (::UA_Argument arg : other.OutputArguments) {
			::UA_Argument ar;
			UA_Argument_init(&ar);
			UA_Argument_copy(&arg, &ar);
			OutputArguments.push_back(ar);
		}
	}

	UA_Method::~UA_Method()
	{
		UA_MethodAttributes_deleteMembers(Attributes);
		UA_MethodAttributes_delete(Attributes);

		for (::UA_Argument arg : InputArguments) {
			UA_Argument_deleteMembers(&arg);
		}
		
		for (::UA_Argument arg : OutputArguments) {
			UA_Argument_deleteMembers(&arg);
		}
	}
}

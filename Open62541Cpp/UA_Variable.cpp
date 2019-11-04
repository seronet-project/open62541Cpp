/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#include "UA_Variable.hpp"
#include <open62541/types_generated_handling.h>

namespace OPEN_65241_CPP_NAMESPACE {

	UA_Variable::UA_Variable() : Attributes(UA_VariableAttributes_new())
	{
		UA_VariableAttributes_init(Attributes);
	}

	UA_Variable::UA_Variable(::UA_VariableAttributes * varAttr, bool takeOwnership)
	{
		if (takeOwnership) {
			Attributes = varAttr;
		}
		else {
			Attributes = UA_VariableAttributes_new();
			UA_VariableAttributes_init(Attributes);
			UA_VariableAttributes_copy(varAttr, Attributes);
		}
	}

	UA_Variable::UA_Variable(const::UA_VariableAttributes * varAttr): UA_Variable()
	{
		UA_VariableAttributes_copy(varAttr, Attributes);
	}

	UA_Variable::UA_Variable(const UA_Variable & other): UA_Variable(other.Attributes)
	{
	}

	UA_Variable::~UA_Variable()
	{
		UA_VariableAttributes_deleteMembers(Attributes);
		UA_VariableAttributes_delete(Attributes);
	}

}

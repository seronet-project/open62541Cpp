/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#ifndef UA_VARIABLE_HPP
#define UA_VARIABLE_HPP

#include "util.hpp"
#include <open62541/types.h>
#include <open62541/types_generated.h>

namespace OPEN_65241_CPP_NAMESPACE
{

	class UA_Variable
	{
	public:
		UA_Variable();

		UA_Variable(::UA_VariableAttributes *varAttr, bool takeOwnership);
		/// Do a copy
		UA_Variable(const ::UA_VariableAttributes *varAttr);
		UA_Variable(const UA_Variable& other);
		virtual ~UA_Variable();

		::UA_VariableAttributes *Attributes;
	};
}

#endif

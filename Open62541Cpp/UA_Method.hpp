/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#ifndef UA_METHOD_HPP
#define UA_METHOD_HPP

#include "util.hpp"
#include <open62541/types.h>
#include <open62541/types_generated.h>
#include <vector>

namespace open62541Cpp
{

	class UA_Method
	{
	public:
		UA_Method();

		UA_Method(::UA_MethodAttributes* methodAttr, bool takeOwnership);
		/// Do a copy
		UA_Method(const ::UA_MethodAttributes* methodAttr);
		UA_Method(const UA_Method& other);
		virtual ~UA_Method();

		::UA_MethodAttributes* Attributes;

		std::vector<::UA_Argument> InputArguments;
		std::vector<::UA_Argument> OutputArguments;
	};

}

#endif

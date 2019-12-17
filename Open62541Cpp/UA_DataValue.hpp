/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#ifndef UA_DATAVALUE_HPP
#define UA_DATAVALUE_HPP

#include "util.hpp"
#include <open62541/types.h>


namespace open62541Cpp
{

	class UA_DataValue
	{
	public:
		UA_DataValue();

		UA_DataValue(::UA_DataValue* dataValue, bool takeOwnership);
		/// Do a copy
		UA_DataValue(const ::UA_DataValue* dataValue);
		UA_DataValue(const ::UA_DataValue dataValue);
		UA_DataValue(const UA_DataValue& other);

		UA_DataValue & operator=(const::UA_DataValue &other);

		virtual ~UA_DataValue();

		::UA_DataValue* DataValue;

	};

}

#endif
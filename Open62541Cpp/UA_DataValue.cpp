/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/
#include "UA_DataValue.hpp"
#include <open62541/types_generated_handling.h>

namespace open62541Cpp
{

	UA_DataValue::UA_DataValue() : DataValue(UA_DataValue_new())
	{
		UA_DataValue_init(DataValue);
	}

	UA_DataValue::UA_DataValue(::UA_DataValue * dataValue, bool takeOwnership)
	{
		if (takeOwnership) {
			DataValue = dataValue;
		}
		else {
			DataValue = UA_DataValue_new();
			UA_DataValue_init(DataValue);
			UA_DataValue_copy(dataValue, DataValue);
		}
	}

	UA_DataValue::UA_DataValue(const::UA_DataValue * dataValue) : UA_DataValue()
	{
		UA_DataValue_copy(dataValue, DataValue);
	}

	UA_DataValue::UA_DataValue(const::UA_DataValue dataValue) : UA_DataValue(&dataValue)
	{
	}

	UA_DataValue::UA_DataValue(const UA_DataValue & other) : UA_DataValue(other.DataValue)
	{
	}

	UA_DataValue & UA_DataValue::operator=(const::UA_DataValue & other)
	{
		UA_DataValue_copy(&other, DataValue);
		return *this;
	}

	UA_DataValue::~UA_DataValue()
	{
		UA_DataValue_deleteMembers(DataValue);
		UA_DataValue_delete(DataValue);
	}

}

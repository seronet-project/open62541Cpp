/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/

#include <sstream>
#include "../util.hpp"

#include "OpcUaErrorException.hpp"

namespace open62541Cpp {
namespace Exceptions {

OpcUaErrorException::OpcUaErrorException(UA_StatusCode UaStatusCode, const std::string &msg)
    : AbstractionLayerException(OpcUaErrorException::generateErrorMsg(UaStatusCode, msg)), StatusCode(UaStatusCode) {}

OpcUaErrorException::OpcUaErrorException(UA_StatusCode UaStatusCode)
    : OpcUaErrorException(UaStatusCode, "") {}

std::string OpcUaErrorException::generateErrorMsg(UA_StatusCode statusCode, const std::string &msg) {
  std::stringstream ss;
  ss << UA_StatusCode_name(statusCode);
  if(!msg.empty())
  {
   ss << " : " << msg;
  }
  return ss.str();
}

}  // namespace Exceptions
}  // namespace open62541Cpp


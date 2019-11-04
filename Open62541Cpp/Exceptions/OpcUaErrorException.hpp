/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  \author Christian von Arnim  - ISW, University of Stuttgart
 *  \author Sebastian Friedl - ISW, University of Stuttgart
 **/

#pragma once

#include <open62541/types.h>

#include "AbstractionLayerException.hpp"

namespace OPEN_65241_CPP_NAMESPACE {
namespace Exceptions {

class OpcUaErrorException :
    public AbstractionLayerException {
 public:

  explicit OpcUaErrorException(UA_StatusCode UaStatusCode);
  OpcUaErrorException(UA_StatusCode UaStatusCode, const std::string &msg);
  const UA_StatusCode StatusCode;
 private:
  static std::string generateErrorMsg(UA_StatusCode statusCode, const std::string &msg);

};


}  // namespace Exceptions
}  // namespace OPEN_65241_CPP_NAMESPACE


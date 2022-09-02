#include "httpadapter/utility/requesthandler.h"

#include <nlohmann/json.hpp>

#include "domain/errors/aliasexistserror.h"
#include "httpadapter/utility/defaultresponse.h"

namespace httpadapter {
RequestHandler::RequestHandler(const Handler& handler) {
  error_handlers_[typeid(nlohmann::json::type_error)] = [](const Request&) {
    return DefaultResponse::MissingData();
  };
  error_handlers_[typeid(domain::AliasExistsError)] = [](const Request&) {
    auto response = Response();
    response.set_code(ResponseStatus::kConflict);
    return response;
  };
}
Response RequestHandler::process(const Request& request) {
  return handler_(request);
}
}  // namespace httpadapter

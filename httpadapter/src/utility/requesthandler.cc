#include "httpadapter/utility/requesthandler.h"

#include <iostream>
#include <nlohmann/json.hpp>

#include "domain/errors/aliasexistserror.h"
#include "httpadapter/utility/defaultresponse.h"

namespace httpadapter {
RequestHandler::RequestHandler(const Handler& handler) : handler_(handler) {
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
  auto response = Response();
  // std::cout << "Response: processing" << std::endl;
  try {
    response = handler_(request);
    // std::cout << "Response: success" << std::endl;
  } catch (...) {
    response = DefaultResponse::ApplicationError();
    std::cout << "Response: error" << std::endl;
  }
  // std::cout << "Response: processed" << std::endl;
  return response;
}
}  // namespace httpadapter

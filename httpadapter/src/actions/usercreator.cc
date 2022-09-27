#include "httpadapter/actions/usercreator.h"

#include <iostream>

#include "application/applicationerror.h"
#include "application/registry.h"
#include "domain/errors/aliasexistserror.h"
#include "httpadapter/converters/credentials.h"
#include "httpadapter/utility/defaultresponse.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target UserCreator::RequestTarget() { return std::string("/api/createuser"); }
Response UserCreator::Post(const Request& request) {
  auto creator = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto credentials = Credentials::ToType(data);
    auto service = application::Registry::GetService();
    std::cout << "Creating user" << std::endl;
    service->CreateUser(credentials);
    auto response = Response();
    response.set_code(ResponseStatus::kCreated);
    return response;
  };
  auto handler = RequestHandler(creator)
                     .handleError<nlohmann::json::type_error>()
                     .handleError<domain::AliasExistsError>();
  auto response = handler.process(request);
  return response;
}
}  // namespace httpadapter

#include "httpadapter/actions/accesstokengetter.h"

#include "application/registry.h"
#include "httpadapter/converters/accesstoken.h"
#include "httpadapter/converters/credentials.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target AccessTokenGetter::RequestTarget() {
  return std::string("/api/getaccesstoken");
}
Response AccessTokenGetter::Post(const Request& request) {
  auto getter = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto credentials = Credentials::ToType(data);
    auto service = application::Registry::GetService();
    auto token = service->GetAccessToken(credentials);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    response.set_body(AccessToken::ToJson(token).dump());
    return response;
  };
  auto handler =
      RequestHandler(getter).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
}
}  // namespace httpadapter

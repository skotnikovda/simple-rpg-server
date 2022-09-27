#include "httpadapter/actions/healer.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/accesstoken.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target Healer::RequestTarget() { return Target("/api/heal"); }
Response Healer::Post(const Request& request) {
  auto healer = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto token = AccessToken::ToType(data);
    auto service = application::Registry::GetService();
    service->Heal(token);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    return response;
  };
  auto handler =
      RequestHandler(healer).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter

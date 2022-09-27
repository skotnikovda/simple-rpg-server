#include "httpadapter/actions/unequiper.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/unequiprequest.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target Unequiper::RequestTarget() { return Target("/api/unequip"); }
Response Unequiper::Post(const Request& request) {
  auto unequiper = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto unequip_request = UnequipRequest::ToType(data);
    auto service = application::Registry::GetService();
    service->Unequip(unequip_request);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    return response;
  };
  auto handler =
      RequestHandler(unequiper).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter

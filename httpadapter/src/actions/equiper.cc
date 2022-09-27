#include "httpadapter/actions/equiper.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/equiprequest.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target Equiper::RequestTarget() { return Target("/api/equip"); }
Response Equiper::Post(const Request& request) {
  auto equiper = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto equip_request = EquipRequest::ToType(data);
    auto service = application::Registry::GetService();
    service->Equip(equip_request);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    return response;
  };
  auto handler =
      RequestHandler(equiper).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter

#include "httpadapter/actions/equipmentgetter.h"

#include "application/registry.h"
#include "httpadapter/converters/accesstoken.h"
#include "httpadapter/converters/equipment.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target EquipmentGetter::RequestTarget() {
  return std::string("/api/equipment");
}
Response EquipmentGetter::Post(const Request& request) {
  auto getter = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto token = AccessToken::ToType(data);
    auto service = application::Registry::GetService();
    auto equipment = service->GetEquipment(token);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    response.set_body(Equipment::ToJson(equipment).dump());
    return response;
  };
  auto handler =
      RequestHandler(getter).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
}
}  // namespace httpadapter

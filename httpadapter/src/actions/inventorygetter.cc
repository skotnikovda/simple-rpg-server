#include "httpadapter/actions/inventorygetter.h"

#include "application/registry.h"
#include "httpadapter/converters/accesstoken.h"
#include "httpadapter/converters/inventory.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target InventoryGetter::RequestTarget() {
  return std::string("/api/inventory");
}
Response InventoryGetter::Post(const Request& request) {
  auto getter = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto token = AccessToken::ToType(data);
    auto service = application::Registry::GetService();
    auto inventory = service->GetInventory(token);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    response.set_body(Inventory::ToJson(inventory).dump());
    return response;
  };
  auto handler =
      RequestHandler(getter).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
}
}  // namespace httpadapter

#include "httpadapter/actions/shopgetter.h"

#include <iostream>

#include "application/registry.h"
#include "httpadapter/converters/shop.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target ShopGetter::RequestTarget() { return std::string("/api/shop"); }
Response ShopGetter::Get(const Request& request) {
  auto getter = [](const Request& request) {
    auto service = application::Registry::GetService();
    std::cout << "ShopGetter::Get" << std::endl;
    auto shop = service->GetShop();
    std::cout << "ShopGetter::Got" << std::endl;
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    response.set_body(Shop::ToJson(shop).dump());
    std::cout << "ShopGetter::Done" << std::endl;
    return response;
  };
  auto handler =
      RequestHandler(getter).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
}
}  // namespace httpadapter

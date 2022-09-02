#include "httpadapter/actions/seller.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/sellrequest.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target Seller::RequestTarget() { return Target("/sell"); }
Response Seller::Post(const Request& request) {
  auto buyer = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto sell_request = SellRequest::ToType(data);
    auto service = application::Registry::GetService();
    service->Sell(sell_request);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    return response;
  };
  auto handler =
      RequestHandler(buyer).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter

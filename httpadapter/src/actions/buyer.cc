#include "httpadapter/actions/buyer.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/buyrequest.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target Buyer::RequestTarget() { return Target("/buy"); }
Response Buyer::Post(const Request& request) {
  auto buyer = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto buy_request = BuyRequest::ToType(data);
    auto service = application::Registry::GetService();
    service->Buy(buy_request);
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

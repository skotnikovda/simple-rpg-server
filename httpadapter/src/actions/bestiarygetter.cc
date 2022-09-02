#include "httpadapter/actions/bestiarygetter.h"

#include "application/registry.h"
#include "httpadapter/converters/bestiary.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target BestiaryGetter::RequestTarget() { return std::string("/api/bestiary"); }
Response BestiaryGetter::Get(const Request& request) {
  auto getter = [](const Request& request) {
    auto service = application::Registry::GetService();
    auto bestiary = service->GetBestiary();
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    response.set_body(Bestiary::ToJson(bestiary).dump());
    return response;
  };
  auto handler =
      RequestHandler(getter).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
}
}  // namespace httpadapter

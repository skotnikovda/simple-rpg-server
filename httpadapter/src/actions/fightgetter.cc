#include "httpadapter/actions/fightgetter.h"

#include "application/registry.h"
#include "httpadapter/converters/accesstoken.h"
#include "httpadapter/converters/fight.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target FightGetter::RequestTarget() { return std::string("/api/fight"); }
Response FightGetter::Post(const Request& request) {
  auto getter = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto token = AccessToken::ToType(data);
    auto service = application::Registry::GetService();
    auto fight = service->GetFight(token);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    response.set_body(Fight::ToJson(fight).dump());
    return response;
  };
  auto handler =
      RequestHandler(getter).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
}
}  // namespace httpadapter

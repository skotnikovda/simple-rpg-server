#include "httpadapter/actions/fightcreator.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/fightrequest.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target FightCreator::RequestTarget() { return Target("/createfight"); }
Response FightCreator::Post(const Request& request) {
  auto creator = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto fight_request = FightRequest::ToType(data);
    auto service = application::Registry::GetService();
    service->CreateFight(fight_request);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    return response;
  };
  auto handler =
      RequestHandler(creator).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter

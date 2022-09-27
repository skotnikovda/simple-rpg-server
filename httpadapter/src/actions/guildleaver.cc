#include "httpadapter/actions/guildleaver.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/accesstoken.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target GuildLeaver::RequestTarget() { return Target("/api/leaveguild"); }
Response GuildLeaver::Post(const Request& request) {
  auto leaver = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto token = AccessToken::ToType(data);
    auto service = application::Registry::GetService();
    service->LeaveGuild(token);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    return response;
  };
  auto handler =
      RequestHandler(leaver).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter

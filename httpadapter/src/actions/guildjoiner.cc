#include "httpadapter/actions/guildjoiner.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/joinguildrequest.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target GuildJoiner::RequestTarget() { return Target("/api/joinguild"); }
Response GuildJoiner::Post(const Request& request) {
  auto joiner = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto join_request = JoinGuildRequest::ToType(data);
    auto service = application::Registry::GetService();
    service->JoinGuild(join_request);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    return response;
  };
  auto handler =
      RequestHandler(joiner).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter

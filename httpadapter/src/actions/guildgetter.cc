#include "httpadapter/actions/guildgetter.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/guild.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target GuildGetter::RequestTarget() { return Target("/api/guild"); }
Response GuildGetter::Post(const Request& request) {
  auto getter = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto guild_id = domain::guild::Id(data["guild_id"]);
    auto service = application::Registry::GetService();
    auto guild = service->GetGuild(guild_id);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    response.set_body(Guild::ToJson(guild).dump());
    return response;
  };
  auto handler =
      RequestHandler(getter).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter

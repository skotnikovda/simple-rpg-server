#include "httpadapter/actions/guildlistgetter.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/guildlist.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target GuildListGetter::RequestTarget() { return Target("/api/guildlist"); }
Response GuildListGetter::Get(const Request& request) {
  auto getter = [](const Request& request) {
    auto service = application::Registry::GetService();
    auto guild_list = service->GetGuilds();
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    response.set_body(GuildList::ToJson(guild_list).dump());
    return response;
  };
  auto handler =
      RequestHandler(getter).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter

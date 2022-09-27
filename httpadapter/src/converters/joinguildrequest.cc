#include "httpadapter/converters/joinguildrequest.h"

#include "httpadapter/converters/accesstoken.h"

namespace httpadapter {
application::JoinGuildRequest JoinGuildRequest::ToType(
    const nlohmann::json& data) {
  auto access_token = AccessToken::ToType(data["access_token"]);
  auto id = domain::guild::Id(data["guild_id"].get<int>());
  return application::JoinGuildRequest(access_token, id);
}
}  // namespace httpadapter

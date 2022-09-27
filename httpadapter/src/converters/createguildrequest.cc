#include "httpadapter/converters/createguildrequest.h"

#include "httpadapter/converters/accesstoken.h"

namespace httpadapter {
application::CreateGuildRequest CreateGuildRequest::ToType(
    const nlohmann::json& data) {
  auto access_token = AccessToken::ToType(data["access_token"]);
  auto name = domain::guild::Name(data["guild_name"].get<std::string>());
  return application::CreateGuildRequest(access_token, name);
}
}  // namespace httpadapter

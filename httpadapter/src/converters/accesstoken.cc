#include "httpadapter/converters/accesstoken.h"

namespace httpadapter {
domain::user::AccessToken AccessToken::ToType(const nlohmann::json& data) {
  auto id = domain::user::Id(data["id"]);
  auto secret = domain::user::Secret(data["secret"]);
  auto access_token = domain::user::AccessToken{id, secret};
  return access_token;
}
nlohmann::json AccessToken::ToJson(const domain::user::AccessToken& data) {
  nlohmann::json json;
  json["id"] = data.id.value();
  json["secret"] = data.secret.value();
  return json;
}
}  // namespace httpadapter

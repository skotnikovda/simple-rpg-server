#include "httpadapter/converters/credentials.h"

namespace httpadapter {
domain::user::Credentials Credentials::ToType(const nlohmann::json& data) {
  auto username = domain::user::Alias(data["alias"]);
  auto password = domain::user::Password(data["password"]);
  auto credentials = domain::user::Credentials{username, password};
  return credentials;
}
}  // namespace httpadapter

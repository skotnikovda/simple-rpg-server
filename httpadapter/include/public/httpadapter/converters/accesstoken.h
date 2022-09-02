#pragma once

#include <nlohmann/json.hpp>

#include "domain/user/accesstoken.h"

namespace httpadapter {
struct AccessToken {
  static domain::user::AccessToken ToType(const nlohmann::json& data);
  static nlohmann::json ToJson(const domain::user::AccessToken& data);
};
}  // namespace httpadapter

#pragma once

#include <nlohmann/json.hpp>

#include "domain/user/credentials.h"

namespace httpadapter {
struct Credentials {
  static domain::user::Credentials ToType(const nlohmann::json& data);
};
}  // namespace httpadapter

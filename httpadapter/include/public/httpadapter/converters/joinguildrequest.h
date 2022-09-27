#pragma once

#include <nlohmann/json.hpp>

#include "application/requests/joinguildrequest.h"

namespace httpadapter {
struct JoinGuildRequest {
  static application::JoinGuildRequest ToType(const nlohmann::json& data);
};
}  // namespace httpadapter

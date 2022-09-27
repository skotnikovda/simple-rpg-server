#pragma once

#include <nlohmann/json.hpp>

#include "application/requests/createguildrequest.h"

namespace httpadapter {
struct CreateGuildRequest {
  static application::CreateGuildRequest ToType(const nlohmann::json& data);
};
}  // namespace httpadapter

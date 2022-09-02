#pragma once

#include <nlohmann/json.hpp>

#include "application/requests/unequiprequest.h"

namespace httpadapter {
struct UnequipRequest {
  static application::UnequipRequest ToType(const nlohmann::json& data);
};
}  // namespace httpadapter

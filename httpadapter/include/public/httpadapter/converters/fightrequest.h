#pragma once

#include <nlohmann/json.hpp>

#include "application/requests/fightrequest.h"

namespace httpadapter {
struct FightRequest {
  static application::FightRequest ToType(const nlohmann::json& data);
};
}  // namespace httpadapter

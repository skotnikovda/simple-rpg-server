#pragma once

#include <nlohmann/json.hpp>

#include "domain/monster.h"

namespace httpadapter {
struct Monster {
  static nlohmann::json ToJson(const domain::Monster&);
};
}  // namespace httpadapter

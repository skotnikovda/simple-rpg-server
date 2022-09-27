#pragma once

#include <nlohmann/json.hpp>
#include <vector>

#include "domain/guild.h"

namespace httpadapter {
struct GuildList {
  static nlohmann::json ToJson(const std::vector<domain::Guild>&);
};
}  // namespace httpadapter

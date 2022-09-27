#pragma once

#include <nlohmann/json.hpp>

#include "domain/guild.h"

namespace httpadapter {
struct Guild {
  static nlohmann::json ToJson(const domain::Guild&);
};
}  // namespace httpadapter

#pragma once

#include <nlohmann/json.hpp>

#include "domain/fight.h"

namespace httpadapter {
struct Fight {
  static nlohmann::json ToJson(const domain::Fight&);
};
}  // namespace httpadapter

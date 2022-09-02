#pragma once

#include <nlohmann/json.hpp>

#include "domain/inventory.h"

namespace httpadapter {
struct Inventory {
  static nlohmann::json ToJson(const domain::Inventory&);
};
}  // namespace httpadapter

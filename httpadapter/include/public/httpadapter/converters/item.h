#pragma once

#include <nlohmann/json.hpp>

#include "domain/item.h"

namespace httpadapter {
struct Item {
  static nlohmann::json ToJson(const domain::Item&);
};
}  // namespace httpadapter

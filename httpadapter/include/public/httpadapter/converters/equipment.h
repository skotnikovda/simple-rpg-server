#pragma once

#include <nlohmann/json.hpp>

#include "domain/equipment.h"

namespace httpadapter {
struct Equipment {
  static std::map<domain::item::Category, std::string> category_map_;
  static nlohmann::json ToJson(const domain::Equipment&);
};
}  // namespace httpadapter

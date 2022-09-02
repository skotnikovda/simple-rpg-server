#pragma once

#include <nlohmann/json.hpp>

#include "domain/shop.h"

namespace httpadapter {
struct Shop {
  static nlohmann::json ToJson(const domain::Shop&);
};
}  // namespace httpadapter

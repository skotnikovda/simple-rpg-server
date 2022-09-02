#pragma once

#include <nlohmann/json.hpp>

#include "domain/bestiary.h"

namespace httpadapter {
struct Bestiary {
  static nlohmann::json ToJson(const domain::Bestiary&);
};
}  // namespace httpadapter

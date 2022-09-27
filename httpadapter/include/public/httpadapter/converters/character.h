#pragma once

#include <nlohmann/json.hpp>

#include "domain/character.h"

namespace httpadapter {
struct Character {
  static nlohmann::json ToJson(const domain::Character&);
};
}  // namespace httpadapter

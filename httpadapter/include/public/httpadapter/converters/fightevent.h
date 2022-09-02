#pragma once

#include <nlohmann/json.hpp>

#include "domain/fight/event.h"

namespace httpadapter {
struct FightEvent {
  static nlohmann::json ToJson(const domain::fight::Event&);
};
}  // namespace httpadapter

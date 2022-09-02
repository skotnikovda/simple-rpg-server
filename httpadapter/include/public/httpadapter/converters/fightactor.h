#pragma once

#include <map>
#include <string>

#include "domain/fight/actor.h"

namespace httpadapter {
struct FightActor {
  static std::map<domain::fight::Actor, std::string> type_map_;
  static std::string ToString(const domain::fight::Actor&);
};
}  // namespace httpadapter

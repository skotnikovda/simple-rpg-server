#pragma once

#include <map>
#include <optional>

#include "domain/character/id.h"
#include "domain/fight.h"

namespace application {
typedef std::map<domain::character::Id, std::optional<domain::Fight>>
    LastFightStorage;
}  // namespace application

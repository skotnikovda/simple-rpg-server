#pragma once

#include "domain/properties/health.h"
#include "domain/properties/level.h"

namespace domain {
namespace character {
struct Service {
  Health GetMaxBaseHealth(const Level&) const;
};
}  // namespace character
}  // namespace domain

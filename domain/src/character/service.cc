#include "domain/character/service.h"

namespace domain {
namespace character {
Health Service::GetMaxBaseHealth(const Level& level) const {
  return level.value() * 20;
}
}  // namespace character
}  // namespace domain

#include "domain/fight/damage.h"

#include <compare>

#include "domain/properties/attack.h"
#include "domain/properties/defense.h"

namespace domain {
namespace fight {
Damage::Damage(const Attack& attack, const Defense& defense)
    : value_(attack.value() - defense.value()) {}
int Damage::value() const { return value_; }
}  // namespace fight
}  // namespace domain

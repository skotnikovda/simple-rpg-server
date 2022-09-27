#include "domain/fight/damage.h"

#include <cmath>
#include <compare>

#include "domain/properties/attack.h"
#include "domain/properties/defense.h"

namespace domain {
namespace fight {
Damage::Damage(const Attack& attack, const Defense& defense)
    : value_(std::max(attack.value() - defense.value(), 0)) {}
int Damage::value() const { return value_; }
}  // namespace fight
}  // namespace domain

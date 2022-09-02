#include "domain/properties/attack.h"

namespace domain {
Attack::Attack(int value) : value_(value) {}
int Attack::value() const { return value_; }
}  // namespace domain

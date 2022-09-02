#include "domain/properties/defense.h"

namespace domain {
Defense::Defense(int value) : value_(value) {}
int Defense::value() const { return value_; }
}  // namespace domain

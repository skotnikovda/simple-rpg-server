#include "domain/properties/level.h"

namespace domain {
Level::Level(int value) : value_(value) {}
int Level::value() const { return value_; }
}  // namespace domain

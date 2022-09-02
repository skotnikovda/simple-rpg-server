#include "domain/properties/health.h"

namespace domain {
Health::Health(int value) : value_(value) {}
int Health::value() const { return value_; }
Health& Health::operator-=(const fight::Damage& damage) {
  value_ -= damage.value();
  if (value_ < 0) value_ = 0;
  return *this;
}
}  // namespace domain

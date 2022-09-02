#include "domain/gold.h"

namespace domain {
Gold::Gold(int value) : value_(value) {}
int Gold::value() const { return value_; }
Gold& Gold::operator+=(const Gold& other) {
  value_ += other.value_;
  return *this;
}
Gold& Gold::operator-=(const Gold& other) {
  value_ -= other.value_;
  return *this;
}
}  // namespace domain

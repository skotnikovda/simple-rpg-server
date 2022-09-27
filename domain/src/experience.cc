#include "domain/experience.h"

namespace domain {
Experience::Experience(int value) : value_(value) {}
int Experience::value() const { return value_; }
Experience& Experience::operator+=(const Experience& other) {
  value_ += other.value_;
  return *this;
}
Experience& Experience::operator-=(const Experience& other) {
  value_ -= other.value_;
  return *this;
}
}  // namespace domain

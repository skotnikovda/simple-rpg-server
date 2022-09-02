#include "domain/experience.h"

namespace domain {
Experience::Experience(int value) : value_(value) {}
int Experience::value() const { return value_; }
}  // namespace domain

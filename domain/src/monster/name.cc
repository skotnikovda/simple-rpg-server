#include "domain/monster/name.h"

namespace domain {
namespace monster {
Name::Name(const std::string& value) : value_(value) {}
std::string Name::value() const { return value_; }
}  // namespace monster
}  // namespace domain

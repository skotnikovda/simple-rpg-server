#include "domain/item/name.h"

namespace domain {
namespace item {
Name::Name(const std::string& value) : value_(value) {}
std::string Name::value() const { return value_; }
}  // namespace item
}  // namespace domain

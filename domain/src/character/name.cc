#include "domain/character/name.h"

namespace domain {
namespace character {
Name::Name(const std::string& value) : value_(value) {}
const std::string& Name::value() const { return value_; }
}  // namespace character
}  // namespace domain

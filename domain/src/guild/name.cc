#include "domain/guild/name.h"

namespace domain {
namespace guild {
Name::Name(const std::string& value) : value_(value) {}
const std::string& Name::value() const { return value_; }
}  // namespace guild
}  // namespace domain

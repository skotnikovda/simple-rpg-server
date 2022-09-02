#include "domain/user/alias.h"

namespace domain {
namespace user {
Alias::Alias(const std::string& value) : value_(value) {}
const std::string& Alias::value() const { return value_; }
}  // namespace user
}  // namespace domain

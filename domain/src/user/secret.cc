#include "domain/user/secret.h"

namespace domain {
namespace user {
Secret::Secret(const std::string& value) : value_(value) {}
const std::string& Secret::value() const { return value_; }
}  // namespace user
}  // namespace domain

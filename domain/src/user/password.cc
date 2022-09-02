#include "domain/user/password.h"

namespace domain {
namespace user {
Password::Password(const std::string& value) : value_(value) {}
const std::string& Password::value() const { return value_; }
}  // namespace user
}  // namespace domain

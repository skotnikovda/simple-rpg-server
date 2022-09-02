#pragma once

#include "alias.h"
#include "password.h"

namespace domain {
namespace user {
struct Credentials {
  Alias alias;
  Password password;
  auto operator<=>(const Credentials&) const = default;
};
}  // namespace user
}  // namespace domain

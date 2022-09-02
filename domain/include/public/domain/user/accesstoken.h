#pragma once

#include "id.h"
#include "secret.h"

namespace domain {
namespace user {
struct AccessToken {
  Id id;
  Secret secret;
};
}  // namespace user
}  // namespace domain

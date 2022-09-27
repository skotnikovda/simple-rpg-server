#pragma once

#include "domain/guild/name.h"
#include "domain/user/accesstoken.h"

namespace application {
struct CreateGuildRequest {
  domain::user::AccessToken token;
  domain::guild::Name name;
};
}  // namespace application

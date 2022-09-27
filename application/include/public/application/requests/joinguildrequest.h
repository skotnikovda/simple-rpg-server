#pragma once

#include "domain/guild/id.h"
#include "domain/user/accesstoken.h"

namespace application {
struct JoinGuildRequest {
  domain::user::AccessToken token;
  domain::guild::Id id;
};
}  // namespace application

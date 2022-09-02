#pragma once

#include "domain/bestiary/monsterindex.h"
#include "domain/user/accesstoken.h"

namespace application {
struct FightRequest {
  domain::user::AccessToken token;
  domain::bestiary::MonsterIndex monster_index;
};
}  // namespace application

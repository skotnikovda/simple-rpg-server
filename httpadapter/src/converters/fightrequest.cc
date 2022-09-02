#include "httpadapter/converters/fightrequest.h"

#include "httpadapter/converters/accesstoken.h"

namespace httpadapter {
application::FightRequest FightRequest::ToType(const nlohmann::json& data) {
  auto access_token = AccessToken::ToType(data);
  auto monster_index =
      domain::bestiary::MonsterIndex(data["monster_index"].get<int>());
  return application::FightRequest{access_token, monster_index};
}
}  // namespace httpadapter

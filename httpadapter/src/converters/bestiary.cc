#include "httpadapter/converters/bestiary.h"

#include "httpadapter/converters/monster.h"

namespace httpadapter {
nlohmann::json Bestiary::ToJson(const domain::Bestiary& bestiary) {
  nlohmann::json json;
  json["monsters"] = nlohmann::json::array();
  for (const auto& monster : bestiary.species()) {
    json["monsters"].push_back(Monster::ToJson(monster));
  }
  return json;
}
}  // namespace httpadapter

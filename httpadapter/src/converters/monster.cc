#include "httpadapter/converters/monster.h"

namespace httpadapter {
nlohmann::json Monster::ToJson(const domain::Monster& monster) {
  nlohmann::json json;
  json["name"] = monster.name().value();
  json["level"] = monster.level().value();
  json["health"] = monster.health().value();
  json["attack"] = monster.attack().value();
  json["defense"] = monster.defense().value();
  return json;
}
}  // namespace httpadapter

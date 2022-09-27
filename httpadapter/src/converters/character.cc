#include "httpadapter/converters/character.h"

#include <iostream>

namespace httpadapter {
nlohmann::json Character::ToJson(const domain::Character& data) {
  nlohmann::json json;
  json["id"] = data.id().value();
  json["name"] = data.name().value();
  json["level"] = data.level().value();
  json["current_experience"] = data.current_experience().value();
  json["required_experience"] = data.required_experience().value();
  json["health"] = data.health().value();
  json["max_health"] = data.max_health().value();
  json["attack"] = data.attack().value();
  json["defense"] = data.defense().value();
  json["gold"] = data.gold().value();
  json["guild_id"] = nullptr;
  std::cout << "Character.Guild" << std::endl;
  if (data.guild_id().has_value()) {
    std::cout << "Has value" << std::endl;
    json["guild_id"] = data.guild_id().value().value();
  }
  return json;
}
}  // namespace httpadapter

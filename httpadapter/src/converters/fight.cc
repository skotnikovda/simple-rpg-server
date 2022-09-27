#include "httpadapter/converters/fight.h"

#include "httpadapter/converters/fightevent.h"

namespace httpadapter {
nlohmann::json Fight::ToJson(const domain::Fight& fight) {
  nlohmann::json json;
  json["events"] = nlohmann::json::array();
  for (const auto& event : fight.events()) {
    json["events"].push_back(FightEvent::ToJson(event));
  }
  json["reward_experience"] = fight.reward_experience().value();
  json["reward_gold"] = fight.reward_gold().value();
  return json;
}
}  // namespace httpadapter

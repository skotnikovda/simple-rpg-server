#include "httpadapter/converters/fight.h"

#include "httpadapter/converters/fightevent.h"

namespace httpadapter {
nlohmann::json Fight::ToJson(const domain::Fight& fight) {
  nlohmann::json json;
  json["events"] = nlohmann::json::array();
  for (const auto& event : fight.events()) {
    json.push_back(FightEvent::ToJson(event));
  }
  return json;
}
}  // namespace httpadapter

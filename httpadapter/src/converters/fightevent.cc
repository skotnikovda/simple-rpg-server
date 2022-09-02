#include "httpadapter/converters/fightevent.h"

#include "httpadapter/converters/fightactor.h"

namespace httpadapter {
nlohmann::json FightEvent::ToJson(const domain::fight::Event& event) {
  nlohmann::json json;
  json["actor"] = FightActor::ToString(event.actor());
  json["damage"] = event.damage().value();
  return json;
}
}  // namespace httpadapter

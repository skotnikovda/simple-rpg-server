#include "httpadapter/converters/guild.h"

namespace httpadapter {
nlohmann::json Guild::ToJson(const domain::Guild& guild) {
  nlohmann::json json;
  json["id"] = guild.id().value();
  json["name"] = guild.name().value();
  json["leader_id"] = guild.leader_id().value();
  json["members"] = nlohmann::json::array();
  for (const auto& member : guild.members()) {
    nlohmann::json member_json;
    member_json["id"] = member.id().value();
    member_json["name"] = member.name().value();
    member_json["level"] = member.level().value();
    json["members"].push_back(member_json);
  }
  return json;
}
}  // namespace httpadapter

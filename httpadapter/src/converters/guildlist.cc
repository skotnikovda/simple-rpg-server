#include "httpadapter/converters/guildlist.h"

#include <iostream>

#include "httpadapter/converters/guild.h"

namespace httpadapter {
nlohmann::json GuildList::ToJson(const std::vector<domain::Guild>& guilds) {
  nlohmann::json json;
  json["guilds"] = nlohmann::json::array();
  for (const auto& guild : guilds) {
    json["guilds"].push_back(Guild::ToJson(guild));
  }
  return json;
}
}  // namespace httpadapter

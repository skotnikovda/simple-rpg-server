#include "httpadapter/converters/inventory.h"

#include "httpadapter/converters/item.h"

namespace httpadapter {
nlohmann::json Inventory::ToJson(const domain::Inventory& inventory) {
  nlohmann::json json;
  json["size"] = inventory.size().value();
  json["items"] = nlohmann::json::array();
  for (const auto& item : inventory.items()) {
    json["items"].push_back(Item::ToJson(item));
  }
  return json;
}
}  // namespace httpadapter

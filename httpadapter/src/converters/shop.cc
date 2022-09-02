#include "httpadapter/converters/shop.h"

#include "httpadapter/converters/item.h"

namespace httpadapter {
nlohmann::json Shop::ToJson(const domain::Shop& shop) {
  nlohmann::json json;
  json["items"] = nlohmann::json::array();
  for (const auto& item : shop.assortment()) {
    json.push_back(Item::ToJson(item));
  }
  return json;
}
}  // namespace httpadapter

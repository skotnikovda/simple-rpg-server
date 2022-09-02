#include "httpadapter/converters/item.h"

#include "httpadapter/converters/itemcategory.h"

namespace httpadapter {
nlohmann::json Item::ToJson(const domain::Item& item) {
  nlohmann::json json;
  json["name"] = item.name().value();
  json["level"] = item.level().value();
  json["attack"] = item.attack().value();
  json["defense"] = item.defense().value();
  json["category"] = ItemCategory::ToString(item.category());
  json["buy_price"] = item.buy_price().value();
  json["sell_price"] = item.sell_price().value();
  return json;
}
}  // namespace httpadapter

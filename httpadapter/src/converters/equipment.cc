#include "httpadapter/converters/equipment.h"

#include "httpadapter/converters/item.h"
#include "httpadapter/converters/itemcategory.h"

namespace httpadapter {
std::map<domain::item::Category, std::string> Equipment::category_map_ = {
    {domain::item::Category::Helmet, "helmet"},
    {domain::item::Category::Platebody, "platebody"},
    {domain::item::Category::Platelegs, "platelegs"},
    {domain::item::Category::Boots, "boots"},
    {domain::item::Category::Sword, "sword"},
    {domain::item::Category::Shield, "shield"}};
nlohmann::json Equipment::ToJson(const domain::Equipment& equipment) {
  nlohmann::json json;
  for (const auto& map_entry : category_map_) {
    auto item = equipment.item(map_entry.first);
    if (item) {
      json[map_entry.second] = Item::ToJson(*item);
    } else {
      json[map_entry.second] = nullptr;
    }
  }
  return json;
}
}  // namespace httpadapter

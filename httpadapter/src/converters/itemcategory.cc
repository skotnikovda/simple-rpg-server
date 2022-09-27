#include "httpadapter/converters/itemcategory.h"

#include <iostream>

namespace httpadapter {
std::map<domain::item::Category, std::string> ItemCategory::type_map_ = {
    {domain::item::Category::Helmet, "helmet"},
    {domain::item::Category::Platebody, "platebody"},
    {domain::item::Category::Platelegs, "platelegs"},
    {domain::item::Category::Boots, "boots"},
    {domain::item::Category::Sword, "sword"},
    {domain::item::Category::Shield, "shield"}};
std::map<std::string, domain::item::Category> ItemCategory::string_map_ = {
    {"helmet", domain::item::Category::Helmet},
    {"platebody", domain::item::Category::Platebody},
    {"platelegs", domain::item::Category::Platelegs},
    {"boots", domain::item::Category::Boots},
    {"sword", domain::item::Category::Sword},
    {"shield", domain::item::Category::Shield}};
domain::item::Category ItemCategory::ToType(const std::string& data) {
  return string_map_[data];
}
std::string ItemCategory::ToString(const domain::item::Category& category) {
  return type_map_[category];
}
}  // namespace httpadapter

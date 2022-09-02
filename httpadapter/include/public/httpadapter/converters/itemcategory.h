#pragma once

#include <map>
#include <string>

#include "domain/item/category.h"

namespace httpadapter {
struct ItemCategory {
  static std::map<domain::item::Category, std::string> type_map_;
  static std::map<std::string, domain::item::Category> string_map_;
  static domain::item::Category ToType(const std::string&);
  static std::string ToString(const domain::item::Category&);
};
}  // namespace httpadapter

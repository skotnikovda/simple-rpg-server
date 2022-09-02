#pragma once

#include <vector>

#include "item.h"
#include "shop/itemindex.h"

namespace domain {
class Shop {
 private:
  static inline std::vector<Item> items_ = {};
  static inline bool initialized_ = false;

 public:
  Shop();
  std::vector<Item> assortment() const;
  Item operator[](const shop::ItemIndex&) const;
};
}  // namespace domain

#pragma once

#include <vector>

#include "inventory/itemindex.h"
#include "item.h"
#include "shop/itemindex.h"

namespace domain {
class Character;
class Shop {
 protected:
  static inline std::vector<Item> items_ = {};

 public:
  std::vector<Item> assortment() const;
  Item operator[](const shop::ItemIndex&) const;
  void AcceptPurchase(Character&, const shop::ItemIndex&) const;
  void AcceptSale(Character&, const inventory::ItemIndex&) const;
};
}  // namespace domain

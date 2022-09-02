#pragma once

#include <vector>

#include "inventory/itemcount.h"
#include "inventory/itemindex.h"
#include "inventory/size.h"
#include "item.h"

namespace domain {
class Inventory {
 private:
  inventory::Size size_;
  std::vector<Item> items_;

 public:
  Inventory(const inventory::Size&, const std::vector<Item>&);
  inventory::Size size() const;
  const std::vector<Item>& items() const;
  const Item& item(const inventory::ItemIndex&) const;
  inventory::ItemCount count() const;
  void Insert(const Item&);
  void Extract(const inventory::ItemIndex&);
};
}  // namespace domain

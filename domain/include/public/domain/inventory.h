#pragma once

#include <vector>

#include "character/id.h"
#include "inventory/itemcount.h"
#include "inventory/itemindex.h"
#include "inventory/size.h"
#include "item.h"

namespace domain {
class Inventory {
 private:
  character::Id id_;
  inventory::Size size_;
  std::vector<Item> items_;

 public:
  Inventory(const character::Id&, const inventory::Size&,
            const std::vector<Item>&);
  character::Id id() const;
  inventory::Size size() const;
  const std::vector<Item>& items() const;
  const Item& item(const inventory::ItemIndex&) const;
  inventory::ItemCount count() const;
  void Insert(const Item&);
  void Extract(const inventory::ItemIndex&);
};
}  // namespace domain

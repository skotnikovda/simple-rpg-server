#pragma once

#include <map>
#include <optional>

#include "item.h"

namespace domain {
class Equipment {
 private:
  std::map<item::Category, std::optional<Item>> items_;

 public:
  Equipment() = default;
  Equipment(std::map<item::Category, std::optional<Item>> items);
  std::optional<Item> item(const item::Category&) const;
  void Equip(const Item&);
  void Unequip(const item::Category&);
  Attack attack() const;
  Defense defense() const;
};
}  // namespace domain

#pragma once

#include <map>
#include <optional>

#include "character/id.h"
#include "item.h"

namespace domain {
class Equipment {
 private:
  character::Id id_;
  std::map<item::Category, std::optional<Item>> items_;

 public:
  Equipment(const character::Id&,
            const std::map<item::Category, std::optional<Item>>&);
  character::Id id() const;
  std::optional<Item> item(const item::Category&) const;
  void Equip(const Item&);
  void Unequip(const item::Category&);
  Attack attack() const;
  Defense defense() const;
};
}  // namespace domain

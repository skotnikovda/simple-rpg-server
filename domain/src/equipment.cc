#include "domain/equipment.h"

#include "domain/domainerror.h"

namespace domain {
Equipment::Equipment(const character::Id& id,
                     const std::map<item::Category, std::optional<Item>>& items)
    : id_(id), items_{items} {}
character::Id Equipment::id() const { return id_; }
std::optional<Item> Equipment::item(const item::Category& category) const {
  if (items_.contains(category)) {
    return items_.at(category);
  }
  return std::nullopt;
}
void Equipment::Equip(const Item& item) {
  if (items_[item.category()].has_value()) {
    throw DomainError(
        "Equipment already has an item equipped in this category");
  }
  items_[item.category()] = item;
}
void Equipment::Unequip(const item::Category& category) {
  if (!items_[category].has_value()) {
    throw DomainError("No item equipped in this category");
  }
  items_[category] = std::nullopt;
}
Attack Equipment::attack() const {
  auto attack_value = int(0);
  for (const auto& [category, item] : items_) {
    if (item.has_value()) {
      attack_value += item->attack().value();
    }
  }
  return Attack(attack_value);
}
Defense Equipment::defense() const {
  auto defense_value = int(0);
  for (const auto& [category, item] : items_) {
    if (item.has_value()) {
      defense_value += item->defense().value();
    }
  }
  return Defense(defense_value);
}
}  // namespace domain

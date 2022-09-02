#include "domain/character.h"

#include <cmath>

namespace domain {
Character::Character(const character::Id& id, const character::Name& name,
                     const Experience& experience, const Health& health,
                     const Inventory& inventory, const Equipment& equipment,
                     const Gold& gold)
    : id_(id),
      name_(name),
      experience_(experience),
      health_(health),
      attack_(0),
      defense_(0),
      inventory_(inventory),
      equipment_(equipment),
      gold_(gold) {
  auto level = this->level();
  attack_ = Attack(level.value() * 5 + equipment_.attack().value());
  defense_ = Defense(level.value() * 5 + equipment_.defense().value());
}
character::Id Character::id() const { return id_; }
character::Name Character::name() const { return name_; }
Experience Character::experience() const { return experience_; }
Level Character::level() const {
  auto experience = experience_.value();
  return static_cast<int>(std::sqrt(experience / 100));
}
Experience Character::current_experience() const {
  auto level = this->level().value();
  auto experience = experience_.value();
  return experience - level * level * 100;
}
Experience Character::required_experience() const {
  auto level = this->level().value();
  auto next_level = level + 1;
  return (next_level * next_level - level * level) * 100;
}
Health Character::health() const { return health_; }
Attack Character::attack() const { return attack_; }
Defense Character::defense() const { return defense_; }
Inventory Character::inventory() const { return inventory_; }
Equipment Character::equipment() const { return equipment_; }
Gold Character::gold() const { return gold_; }
void Character::Buy(const Item& item) {
  gold_ -= item.buy_price();
  inventory_.Insert(item);
}
void Character::Sell(const inventory::ItemIndex& index) {
  auto item = inventory_.item(index);
  gold_ += item.sell_price();
  inventory_.Extract(index);
}
void Character::Equip(const inventory::ItemIndex& index) {
  auto item = inventory_.item(index);
  auto equiped_item = equipment_.item(item.category());
  if (equiped_item.has_value()) {
    inventory_.Insert(*equiped_item);
    equipment_.Unequip(item.category());
  }
  equipment_.Equip(item);
  inventory_.Extract(index);
}
void Character::Unequip(const item::Category& category) {
  auto equiped_item = equipment_.item(category);
  if (equiped_item.has_value()) {
    inventory_.Insert(*equiped_item);
    equipment_.Unequip(category);
  }
}
void Character::TakeDamage(const fight::Damage& damage) { health_ -= damage; }
bool Character::IsAlive() const { return health_.value() > 0; }
}  // namespace domain

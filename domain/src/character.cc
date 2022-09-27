#include "domain/character.h"

#include <cmath>

#include "domain/guild.h"
#include "domain/shop.h"

namespace domain {
Character::Character(const character::Id& id, const character::Name& name,
                     const Experience& experience, const Health& health,
                     Inventory& inventory, Equipment& equipment,
                     const Gold& gold, const std::optional<guild::Id>& guild_id)
    : id_(id),
      name_(name),
      experience_(experience),
      health_(health),
      attack_(0),
      defense_(0),
      inventory_(inventory),
      equipment_(equipment),
      gold_(gold),
      guild_id_(guild_id) {
  auto level = this->level();
  attack_ = Attack(level.value() * 5 + equipment_.attack().value());
  defense_ = Defense(level.value() * 2 + equipment_.defense().value());
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
Health Character::max_health() const {
  auto level = this->level().value();
  return Health(level * 20);
}
Attack Character::attack() const { return attack_; }
Defense Character::defense() const { return defense_; }
Inventory& Character::inventory() { return inventory_; }
Equipment& Character::equipment() { return equipment_; }
Gold Character::gold() const { return gold_; }
void Character::Buy(const shop::ItemIndex& index, const Shop& shop) {
  shop.AcceptPurchase(*this, index);
}
void Character::Sell(const inventory::ItemIndex& index, const Shop& shop) {
  shop.AcceptSale(*this, index);
}
void Character::Take(const Item& item) { inventory_.Insert(item); }
Item Character::Give(const inventory::ItemIndex& index) {
  auto item = inventory_.item(index);
  inventory_.Extract(index);
  return item;
}
void Character::Take(const Gold& gold) { gold_ += gold; }
Gold Character::Give(const Gold& gold) {
  gold_ -= gold;
  return gold;
}
void Character::Take(const Experience& experience) {
  auto old_level = this->level();
  experience_ += experience;
  auto level = this->level();
  if (old_level != level) {
    auto max_health = this->max_health();
    health_ = max_health;
  }
  attack_ = Attack(level.value() * 5 + equipment_.attack().value());
  defense_ = Defense(level.value() * 2 + equipment_.defense().value());
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
  attack_ = Attack(level().value() * 5 + equipment_.attack().value());
  defense_ = Defense(level().value() * 2 + equipment_.defense().value());
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
void Character::Heal(const Health& health) { health_ += health; }
std::optional<guild::Id> Character::guild_id() const { return guild_id_; }
void Character::JoinGuild(const Guild& guild) { guild_id_ = guild.id(); }
void Character::LeaveGuild() { guild_id_ = std::nullopt; }
}  // namespace domain

#pragma once

#include "character/id.h"
#include "character/name.h"
#include "domain/item/category.h"
#include "equipment.h"
#include "experience.h"
#include "fight/damage.h"
#include "gold.h"
#include "inventory.h"
#include "properties/attack.h"
#include "properties/defense.h"
#include "properties/health.h"

namespace domain {
class Character {
 private:
  character::Id id_;
  character::Name name_;
  Experience experience_;
  Health health_;
  Attack attack_;
  Defense defense_;
  Inventory inventory_;
  Equipment equipment_;
  Gold gold_;

 public:
  Character(const character::Id&, const character::Name&, const Experience&,
            const Health&, const Inventory&, const Equipment&, const Gold&);
  character::Id id() const;
  character::Name name() const;
  Experience experience() const;
  Level level() const;
  Experience current_experience() const;
  Experience required_experience() const;
  Health health() const;
  Attack attack() const;
  Defense defense() const;
  Inventory inventory() const;
  Equipment equipment() const;
  Gold gold() const;
  void Buy(const Item&);
  void Sell(const inventory::ItemIndex&);
  void Equip(const inventory::ItemIndex&);
  void Unequip(const item::Category&);
  void TakeDamage(const fight::Damage&);
  bool IsAlive() const;
  auto operator<=>(const Character& other) const { return id_ <=> other.id_; }
};
}  // namespace domain

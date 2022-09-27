#pragma once

#include <optional>

#include "character/id.h"
#include "character/name.h"
#include "domain/item/category.h"
#include "equipment.h"
#include "experience.h"
#include "fight/damage.h"
#include "gold.h"
#include "guild/id.h"
#include "inventory.h"
#include "properties/attack.h"
#include "properties/defense.h"
#include "properties/health.h"
#include "shop/itemindex.h"

namespace domain {
class Shop;
class Guild;
class Character {
 private:
  character::Id id_;
  character::Name name_;
  Experience experience_;
  Health health_;
  Attack attack_;
  Defense defense_;
  Inventory& inventory_;
  Equipment& equipment_;
  Gold gold_;
  std::optional<guild::Id> guild_id_;

 public:
  Character(const character::Id&, const character::Name&, const Experience&,
            const Health&, Inventory&, Equipment&, const Gold&,
            const std::optional<guild::Id>&);
  character::Id id() const;
  character::Name name() const;
  Experience experience() const;
  Level level() const;
  Experience current_experience() const;
  Experience required_experience() const;
  Health health() const;
  Health max_health() const;
  Attack attack() const;
  Defense defense() const;
  Inventory& inventory();
  Equipment& equipment();
  Gold gold() const;
  void Buy(const shop::ItemIndex&, const Shop&);
  void Sell(const inventory::ItemIndex&, const Shop&);
  void Take(const Item&);
  Item Give(const inventory::ItemIndex&);
  void Take(const Gold&);
  Gold Give(const Gold&);
  void Take(const Experience&);
  void Equip(const inventory::ItemIndex&);
  void Unequip(const item::Category&);
  void TakeDamage(const fight::Damage&);
  bool IsAlive() const;
  void Heal(const Health&);
  std::optional<guild::Id> guild_id() const;
  void JoinGuild(const Guild&);
  void LeaveGuild();
  auto operator<=>(const Character& other) const { return id_ <=> other.id_; }
};
}  // namespace domain

#pragma once

#include "experience.h"
#include "fight/damage.h"
#include "gold.h"
#include "monster/id.h"
#include "monster/name.h"
#include "properties/attack.h"
#include "properties/defense.h"
#include "properties/health.h"
#include "properties/level.h"

namespace domain {
class Monster {
 private:
  monster::Id id_;
  monster::Name name_;
  Level level_;
  Health health_;
  Attack attack_;
  Defense defense_;
  Experience experience_;
  Gold gold_;

 public:
  Monster(const monster::Id&, const monster::Name&, const Level&, const Health&,
          const Attack&, const Defense&, const Experience&, const Gold&);
  monster::Id id() const;
  monster::Name name() const;
  Level level() const;
  Health health() const;
  Attack attack() const;
  Defense defense() const;
  Experience experience() const;
  Gold gold() const;
  void TakeDamage(const fight::Damage&);
  bool IsAlive() const;
};
}  // namespace domain

#include "domain/monster.h"

namespace domain {
Monster::Monster(const monster::Name& name, const Level& level,
                 const Health& health, const Attack& attack,
                 const Defense& defense, const Experience& experience,
                 const Gold& gold)
    : name_(name),
      level_(level),
      health_(health),
      attack_(attack),
      defense_(defense),
      experience_(experience),
      gold_(gold) {}
monster::Name Monster::name() const { return name_; }
Level Monster::level() const { return level_; }
Health Monster::health() const { return health_; }
Attack Monster::attack() const { return attack_; }
Defense Monster::defense() const { return defense_; }
Experience Monster::experience() const { return experience_; }
Gold Monster::gold() const { return gold_; }
void Monster::TakeDamage(const fight::Damage& damage) { health_ -= damage; }
bool Monster::IsAlive() const { return health_.value() > 0; }
}  // namespace domain

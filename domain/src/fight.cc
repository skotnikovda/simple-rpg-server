#include "domain/fight.h"

namespace domain {
Fight::Fight(Character& character, Monster& monster) {
  while (character.IsAlive() && monster.IsAlive()) {
    auto character_damage =
        fight::Damage(character.attack(), monster.defense());
    monster.TakeDamage(character_damage);
    events_.push_back(fight::Event(fight::Actor::Character, character_damage));
    if (!monster.IsAlive()) break;
    auto monster_damage = fight::Damage(monster.attack(), character.defense());
    character.TakeDamage(monster_damage);
    events_.push_back(fight::Event(fight::Actor::Monster, monster_damage));
  }
}
std::vector<fight::Event> Fight::events() const { return events_; }
}  // namespace domain

#include "domain/fight.h"

#include <iostream>

namespace domain {
Fight::Fight(Character& character, Monster& monster)
    : reward_experience_(0), reward_gold_(0) {
  std::cout << "character:" << std::endl;
  std::cout << "attack:" << character.attack().value() << std::endl;
  std::cout << "defense:" << character.defense().value() << std::endl;
  std::cout << "monster:" << std::endl;
  std::cout << "attack:" << monster.attack().value() << std::endl;
  std::cout << "defense:" << monster.defense().value() << std::endl;
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
  if (character.IsAlive()) {
    std::cout << "character wins" << std::endl;
    reward_experience_ = monster.experience();
    reward_gold_ = monster.gold();
    character.Take(reward_experience_);
    character.Take(reward_gold_);
  }
}
std::vector<fight::Event> Fight::events() const { return events_; }
Experience Fight::reward_experience() const { return reward_experience_; }
Gold Fight::reward_gold() const { return reward_gold_; }
}  // namespace domain

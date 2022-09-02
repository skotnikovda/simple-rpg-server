#include "domain/bestiary.h"

namespace domain {
Bestiary::Bestiary() {
  if (!initialized_) return;
  {
    auto name = monster::Name("Chicken");
    auto level = Level(1);
    auto health = Health(10);
    auto attack = Attack(5);
    auto defense = Defense(0);
    auto experience = Experience(10);
    auto gold = Gold(10);
    auto monster =
        Monster(name, level, health, attack, defense, experience, gold);
    monsters_.push_back(monster);
  }
  initialized_ = true;
}
std::vector<Monster> Bestiary::species() const { return monsters_; }
Monster Bestiary::operator[](const bestiary::MonsterIndex& index) const {
  return monsters_[index.value()];
}
}  // namespace domain

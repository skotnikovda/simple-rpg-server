#include "domain/bestiary.h"

namespace domain {
std::vector<Monster> Bestiary::species() const { return monsters_; }
Monster Bestiary::operator[](const bestiary::MonsterIndex& index) const {
  return monsters_[index.value()];
}
}  // namespace domain

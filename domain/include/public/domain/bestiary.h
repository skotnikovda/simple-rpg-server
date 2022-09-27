#pragma once

#include <vector>

#include "bestiary/monsterindex.h"
#include "domain/monster.h"

namespace domain {
class Bestiary {
 protected:
  static inline std::vector<Monster> monsters_ = {};

 public:
  std::vector<Monster> species() const;
  Monster operator[](const bestiary::MonsterIndex&) const;
};
}  // namespace domain

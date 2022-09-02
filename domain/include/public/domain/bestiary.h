#pragma once

#include <vector>

#include "bestiary/monsterindex.h"
#include "domain/monster.h"

namespace domain {
class Bestiary {
 private:
  static inline std::vector<Monster> monsters_ = {};
  static inline bool initialized_ = false;

 public:
  Bestiary();
  std::vector<Monster> species() const;
  Monster operator[](const bestiary::MonsterIndex&) const;
};
}  // namespace domain

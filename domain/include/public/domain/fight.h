#pragma once

#include <vector>

#include "character.h"
#include "fight/event.h"
#include "monster.h"

namespace domain {
class Fight {
 private:
  std::vector<fight::Event> events_;
  Experience reward_experience_;
  Gold reward_gold_;

 public:
  Fight(Character&, Monster&);
  std::vector<fight::Event> events() const;
  Experience reward_experience() const;
  Gold reward_gold() const;
};
}  // namespace domain

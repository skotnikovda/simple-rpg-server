#pragma once

#include <vector>

#include "character.h"
#include "fight/event.h"
#include "monster.h"

namespace domain {
class Fight {
 private:
  std::vector<fight::Event> events_;

 public:
  Fight(Character&, Monster&);
  std::vector<fight::Event> events() const;
};
}  // namespace domain

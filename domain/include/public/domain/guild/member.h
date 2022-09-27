#pragma once

#include "domain/character.h"
#include "domain/character/id.h"
#include "domain/character/name.h"
#include "domain/experience.h"
#include "domain/properties/level.h"

namespace domain {
namespace guild {
class Member {
 private:
  character::Id id_;
  character::Name name_;
  Level level_;

 public:
  Member(const character::Id&, const character::Name&, const Experience&);
  Member(const Character&);
  character::Id id() const;
  character::Name name() const;
  Level level() const;
};
}  // namespace guild
}  // namespace domain

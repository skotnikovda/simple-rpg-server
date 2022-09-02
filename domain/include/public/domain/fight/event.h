#pragma once

#include "actor.h"
#include "damage.h"

namespace domain {
namespace fight {
class Event {
 private:
  Actor actor_;
  Damage damage_;

 public:
  Event(const Actor&, const Damage&);
  Actor actor() const;
  Damage damage() const;
};
}  // namespace fight
}  // namespace domain

#pragma once

#include "domain/fight/damage.h"

namespace domain {
class Health {
 private:
  int value_;

 public:
  Health(int);
  int value() const;
  Health& operator-=(const fight::Damage&);
};
}  // namespace domain

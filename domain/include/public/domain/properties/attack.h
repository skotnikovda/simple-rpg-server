#pragma once

namespace domain {
class Attack {
 private:
  int value_;

 public:
  Attack(int);
  int value() const;
};
}  // namespace domain

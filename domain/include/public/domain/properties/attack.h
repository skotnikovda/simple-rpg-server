#pragma once

namespace domain {
class Attack {
 private:
  int value_;

 public:
  Attack(int);
  int value() const;
  auto operator<=>(const Attack&) const = default;
};
}  // namespace domain

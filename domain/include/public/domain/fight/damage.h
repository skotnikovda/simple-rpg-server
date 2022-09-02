#pragma once

namespace domain {
class Attack;
class Defense;
namespace fight {
class Damage {
 private:
  int value_;

 public:
  Damage(const Attack&, const Defense&);
  int value() const;
};
}  // namespace fight
}  // namespace domain

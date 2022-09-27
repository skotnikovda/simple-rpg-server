#pragma once

namespace domain {
class Level {
 private:
  int value_;

 public:
  Level(int);
  int value() const;
  auto operator<=>(const Level&) const = default;
};
}  // namespace domain

#pragma once

namespace domain {
class Level {
 private:
  int value_;

 public:
  Level(int);
  int value() const;
};
}  // namespace domain

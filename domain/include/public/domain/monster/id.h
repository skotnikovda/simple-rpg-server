#pragma once

namespace domain {
namespace monster {
class Id {
 private:
  int value_;

 public:
  explicit Id(int);
  int value() const;
};
}  // namespace monster
}  // namespace domain

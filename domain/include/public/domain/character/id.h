#pragma once

namespace domain {
namespace character {
class Id {
 private:
  int value_;

 public:
  Id(int);
  int value() const;
  auto operator<=>(const Id&) const = default;
};
}  // namespace character
}  // namespace domain

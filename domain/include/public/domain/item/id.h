#pragma once

namespace domain {
namespace item {
class Id {
 private:
  int value_;

 public:
  Id(int);
  int value() const;
  auto operator<=>(const Id&) const = default;
};
}  // namespace item
}  // namespace domain

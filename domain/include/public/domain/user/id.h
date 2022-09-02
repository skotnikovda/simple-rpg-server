#pragma once

#include <compare>

namespace domain {
namespace user {
class Id {
 private:
  int value_;

 public:
  Id(int);
  int value() const;
  auto operator<=>(const Id&) const = default;
};
}  // namespace user
}  // namespace domain

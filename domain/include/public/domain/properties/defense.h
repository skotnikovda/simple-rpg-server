#pragma once

namespace domain {
class Defense {
 private:
  int value_;

 public:
  Defense(int);
  int value() const;
  auto operator<=>(const Defense&) const = default;
};
}  // namespace domain

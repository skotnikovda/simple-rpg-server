#pragma once

namespace domain {
class Gold {
 private:
  int value_;

 public:
  Gold(int value);
  int value() const;
  Gold& operator+=(const Gold&);
  Gold& operator-=(const Gold&);
  auto operator<=>(const Gold&) const = default;
};
}  // namespace domain

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
};
}  // namespace domain

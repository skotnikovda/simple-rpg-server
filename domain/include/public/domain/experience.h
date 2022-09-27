#pragma once

namespace domain {
class Experience {
 private:
  int value_;

 public:
  Experience(int);
  int value() const;
  Experience& operator+=(const Experience&);
  Experience& operator-=(const Experience&);
};
}  // namespace domain

#pragma once

namespace domain {
class Experience {
 private:
  int value_;

 public:
  Experience(int);
  int value() const;
};
}  // namespace domain

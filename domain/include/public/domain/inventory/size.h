#pragma once

namespace domain {
namespace inventory {
class Size {
 private:
  int value_;

 public:
  Size(int);
  int value() const;
};
}  // namespace inventory
}  // namespace domain

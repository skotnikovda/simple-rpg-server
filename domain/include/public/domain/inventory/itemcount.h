#pragma once

namespace domain {
namespace inventory {
class ItemCount {
 private:
  int value_;

 public:
  ItemCount(int);
  int value() const;
};
}  // namespace inventory
}  // namespace domain

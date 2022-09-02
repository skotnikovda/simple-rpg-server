#pragma once

namespace domain {
namespace inventory {
class ItemIndex {
 private:
  int value_;

 public:
  ItemIndex(int);
  int value() const;
};
}  // namespace inventory
}  // namespace domain

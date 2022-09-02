#pragma once

namespace domain {
namespace shop {
class ItemIndex {
 private:
  int value_;

 public:
  ItemIndex(int);
  int value() const;
};
}  // namespace shop
}  // namespace domain

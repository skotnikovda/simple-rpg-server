#include "domain/shop/itemindex.h"

namespace domain {
namespace shop {
ItemIndex::ItemIndex(int value) : value_(value) {}
int ItemIndex::value() const { return value_; }
}  // namespace shop
}  // namespace domain

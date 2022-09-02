#include "domain/inventory/itemcount.h"

namespace domain {
namespace inventory {
ItemCount::ItemCount(int value) : value_(value) {}
int ItemCount::value() const { return value_; }
}  // namespace inventory
}  // namespace domain

#include "domain/inventory/itemindex.h"

namespace domain {
namespace inventory {
ItemIndex::ItemIndex(int value) : value_(value) {}
int ItemIndex::value() const { return value_; }
}  // namespace inventory
}  // namespace domain

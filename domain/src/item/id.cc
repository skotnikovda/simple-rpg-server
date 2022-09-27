#include "domain/item/id.h"

namespace domain {
namespace item {
Id::Id(int value) : value_(value) {}
int Id::value() const { return value_; }
}  // namespace item
}  // namespace domain

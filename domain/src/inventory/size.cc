#include "domain/inventory/size.h"

namespace domain {
namespace inventory {
Size::Size(int value) : value_(value) {}
int Size::value() const { return value_; }
}  // namespace inventory
}  // namespace domain

#include "domain/monster/id.h"

namespace domain {
namespace monster {
Id::Id(int value) : value_(value) {}
int Id::value() const { return value_; }
}  // namespace monster
}  // namespace domain

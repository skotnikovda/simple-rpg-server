#include "domain/character/id.h"

namespace domain {
namespace character {
Id::Id(int value) : value_(value) {}
int Id::value() const { return value_; }
}  // namespace character
}  // namespace domain

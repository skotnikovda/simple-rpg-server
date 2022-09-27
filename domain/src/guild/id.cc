#include "domain/guild/id.h"

namespace domain {
namespace guild {
Id::Id(int value) : value_(value) {}
int Id::value() const { return value_; }
}  // namespace guild
}  // namespace domain

#include "domain/user/id.h"

namespace domain {
namespace user {
Id::Id(int value) : value_(value) {}
int Id::value() const { return value_; }
}  // namespace user
}  // namespace domain

#include "domain/guild/leaderid.h"

namespace domain {
namespace guild {
LeaderId::LeaderId(int value) : value_(value) {}
int LeaderId::value() const { return value_; }
}  // namespace guild
}  // namespace domain

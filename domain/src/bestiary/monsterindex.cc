#include "domain/bestiary/monsterindex.h"

namespace domain {
namespace bestiary {
MonsterIndex::MonsterIndex(int value) : value_(value) {}
int MonsterIndex::value() const { return value_; }
}  // namespace bestiary
}  // namespace domain

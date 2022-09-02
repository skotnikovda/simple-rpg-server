#include "httpadapter/converters/fightactor.h"

namespace httpadapter {
std::map<domain::fight::Actor, std::string> FightActor::type_map_ = {
    {domain::fight::Actor::Character, "character"},
    {domain::fight::Actor::Monster, "monster"}};
std::string FightActor::ToString(const domain::fight::Actor& actor) {
  return type_map_[actor];
}
}  // namespace httpadapter

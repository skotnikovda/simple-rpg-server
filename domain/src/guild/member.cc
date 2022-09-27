#include "domain/guild/member.h"

#include <cmath>

namespace domain {
namespace guild {
Member::Member(const character::Id& id, const character::Name& name,
               const Experience& experience)
    : id_(id),
      name_(name),
      level_(static_cast<int>(std::sqrt(experience.value() / 100))) {}
Member::Member(const Character& character)
    : Member(character.id(), character.name(), character.experience()) {}
character::Id Member::id() const { return id_; }
character::Name Member::name() const { return name_; }
Level Member::level() const { return level_; }
}  // namespace guild
}  // namespace domain

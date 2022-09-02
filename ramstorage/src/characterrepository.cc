#include "ramstorage/characterrepository.h"

#include <algorithm>
#include <stdexcept>

namespace ramstorage {
std::vector<domain::Character> CharacterRepository::characters_ = {};
void CharacterRepository::Add(const domain::Character& character) {
  auto id = character.id();
  for (auto& character : characters_)
    if (character.id() == id)
      throw std::runtime_error("Character id duplicates existing character");
  characters_.push_back(character);
  std::sort(characters_.begin(), characters_.end());
}
domain::Character& CharacterRepository::operator[](
    const domain::character::Id& id) {
  for (auto& character : characters_)
    if (character.id() == id) return character;
  throw std::runtime_error("Character not found");
}
const domain::Character& CharacterRepository::operator[](
    const domain::character::Id& id) const {
  for (const auto& character : characters_)
    if (character.id() == id) return character;
  throw std::runtime_error("Character not found");
}
}  // namespace ramstorage

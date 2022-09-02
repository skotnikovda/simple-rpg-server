#pragma once

#include "domain/character/repository.h"

namespace ramstorage {
class CharacterRepository : public domain::character::Repository {
 private:
  static std::vector<domain::Character> characters_;

 public:
  void Add(const domain::Character&) override;
  domain::Character& operator[](const domain::character::Id&) override;
  const domain::Character& operator[](
      const domain::character::Id&) const override;
};
}  // namespace ramstorage

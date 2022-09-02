#pragma once

#include "domain/game/characterrepository.h"

namespace postgresadapter {
class CharacterRepository : public domain::game::CharacterRepository {
 public:
  CharacterRepository(const std::string&);
  domain::game::Character GetById(int) override;
};
}  // namespace postgresadapter

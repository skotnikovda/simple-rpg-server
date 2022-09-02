#pragma once

#include "domain/game/enemyrepository.h"

namespace postgresadapter {
class EnemyRepository : public domain::game::EnemyRepository {
 private:
  std::string connection_string_;

 public:
  EnemyRepository(const std::string&);
  std::vector<domain::game::Enemy> GetAll() override;
  domain::game::Enemy GetById(int) override;
};
}  // namespace postgresadapter

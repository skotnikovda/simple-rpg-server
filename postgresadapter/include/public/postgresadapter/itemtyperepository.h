#pragma once

#include <map>
#include <string>
#include <vector>

#include "domain/game/itemtyperepository.h"

namespace postgresadapter {
class ItemTypeRepository : public domain::game::ItemTypeRepository {
 private:
  std::string connection_string_;
  std::map<std::string, domain::game::Shape> shape_map_;

 public:
  ItemTypeRepository(const std::string& connection_string);
  std::vector<domain::game::ItemType> GetAll() override;
  domain::game::ItemType GetById(int id) override;
};
}  // namespace postgresadapter

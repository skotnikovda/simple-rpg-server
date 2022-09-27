#pragma once

#include <string>
#include <vector>

#include "domain/character/repository.h"
#include "equipmentrepository.h"
#include "inventoryrepository.h"

namespace postgresadapter {
class CharacterRepository : public domain::character::Repository {
 private:
  std::string connection_string_;
  std::vector<domain::Character> characters_;
  InventoryRepository inventory_repository_;
  EquipmentRepository equipment_repository_;

 public:
  CharacterRepository(const std::string&, const InventoryRepository&,
                      const EquipmentRepository&);
  void Add(domain::Character&) override;
  domain::Character& operator[](const domain::character::Id&) override;
  void Commit() override;
};
}  // namespace postgresadapter

#pragma once

#include "domain/game/inventoryrepository.h"

namespace postgresadapter {
class InventoryRepository : public domain::game::InventoryRepository {
 private:
  std::string connection_string_;

 public:
  InventoryRepository(const std::string& connection_string);
  Inventory GetByOwnerId(int owner_id) override;
};
}  // namespace postgresadapter

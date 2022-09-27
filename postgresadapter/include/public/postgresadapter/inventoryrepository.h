#pragma once

#include <string>
#include <vector>

#include "domain/inventory.h"

namespace postgresadapter {
class InventoryRepository {
 private:
  std::vector<domain::Inventory> inventories_;
  std::string connection_string_;

 public:
  InventoryRepository(const std::string& connection_string);
  void Add(const domain::Inventory&);
  domain::Inventory& operator[](const domain::character::Id&);
  void Commit();
};
}  // namespace postgresadapter

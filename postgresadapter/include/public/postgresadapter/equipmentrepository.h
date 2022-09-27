#pragma once

#include <string>
#include <vector>

#include "domain/equipment.h"

namespace postgresadapter {
class EquipmentRepository {
 private:
  std::vector<domain::Equipment> equipments_;
  std::string connection_string_;

 public:
  EquipmentRepository(const std::string& connection_string);
  void Add(const domain::Equipment&);
  domain::Equipment& operator[](const domain::character::Id&);
  void Commit();
};
}  // namespace postgresadapter

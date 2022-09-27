#pragma once

#include <map>
#include <pqxx/pqxx>

#include "domain/item.h"

namespace postgresadapter {
class ItemConverter {
 public:
  static std::map<std::string, domain::item::Category> map_;
  static domain::Item Convert(const pqxx::row&);
};
}  // namespace postgresadapter

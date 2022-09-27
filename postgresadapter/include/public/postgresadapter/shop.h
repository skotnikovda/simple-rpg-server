#pragma once

#include "domain/shop.h"

namespace postgresadapter {
class Shop : public domain::Shop {
 public:
  Shop(const std::string&);
};
}  // namespace postgresadapter

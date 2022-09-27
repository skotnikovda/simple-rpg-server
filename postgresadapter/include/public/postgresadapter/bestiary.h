#pragma once

#include <string>

#include "domain/bestiary.h"

namespace postgresadapter {
class Bestiary : public domain::Bestiary {
 public:
  Bestiary(const std::string&);
};
}  // namespace postgresadapter

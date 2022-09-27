#pragma once

#include "domain/character.h"

namespace domain {
namespace character {
class Repository {
 public:
  virtual ~Repository() = default;
  virtual void Add(Character&) = 0;
  virtual Character& operator[](const Id&) = 0;
  virtual void Commit() = 0;
};
}  // namespace character
}  // namespace domain

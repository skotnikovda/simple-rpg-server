#pragma once

#include "domain/character.h"

namespace domain {
namespace character {
class Repository {
 public:
  virtual ~Repository() = default;
  virtual void Add(const Character&) = 0;
  virtual Character& operator[](const Id&) = 0;
  virtual const Character& operator[](const Id&) const = 0;
};
}  // namespace character
}  // namespace domain

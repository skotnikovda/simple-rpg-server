#pragma once

#include "domain/guild.h"
#include "member.h"

namespace domain {
namespace guild {
class Repository {
 public:
  virtual ~Repository() = default;
  virtual void Add(const Guild&) = 0;
  virtual void Remove(const Id&) = 0;
  virtual std::vector<Guild> GetAll() = 0;
  virtual Guild& operator[](const guild::Id&) = 0;
  virtual void Commit() = 0;
};
}  // namespace guild
}  // namespace domain

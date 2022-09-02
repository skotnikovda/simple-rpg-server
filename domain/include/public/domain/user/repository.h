#pragma once

#include "domain/user.h"

namespace domain {
namespace user {
class Repository {
 public:
  virtual ~Repository() = default;
  virtual Id MinimalFreeId() const = 0;
  virtual bool IsAliasUnique(const Alias&) const = 0;
  virtual void Add(const User&) = 0;
  virtual User& operator[](const Id&) = 0;
  virtual const User& operator[](const Id&) const = 0;
  virtual User& operator[](const Credentials&) = 0;
  virtual const User& operator[](const Credentials&) const = 0;
};
}  // namespace user
}  // namespace domain

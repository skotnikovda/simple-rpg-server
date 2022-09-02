#pragma once

#include <vector>

#include "domain/user/repository.h"

namespace ramstorage {
class UserRepository : public domain::user::Repository {
 private:
  static std::vector<domain::User> users_;

 public:
  domain::user::Id MinimalFreeId() const override;
  bool IsAliasUnique(const domain::user::Alias&) const override;
  void Add(const domain::User&) override;
  domain::User& operator[](const domain::user::Credentials&) override;
  const domain::User& operator[](
      const domain::user::Credentials&) const override;
  domain::User& operator[](const domain::user::Id&) override;
  const domain::User& operator[](const domain::user::Id&) const override;
};
}  // namespace ramstorage

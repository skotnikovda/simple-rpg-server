#pragma once

#include <vector>

#include "domain/user/repository.h"

namespace postgresadapter {
class UserRepository : public domain::user::Repository {
 private:
  std::string connection_string_;
  std::vector<domain::User> users_;

 public:
  UserRepository(const std::string&);
  domain::user::Id MinimalFreeId() const override;
  bool IsAliasUnique(const domain::user::Alias&) const override;
  void Add(const domain::User&) override;
  domain::User& operator[](const domain::user::Id&) override;
  domain::User& operator[](const domain::user::Credentials&) override;
  void Commit() override;
};
}  // namespace postgresadapter

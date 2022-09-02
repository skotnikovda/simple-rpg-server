#pragma once

#include "domain/access/userrepository.h"

namespace postgresadapter {
class UserRepository : public domain::access::UserRepository {
 private:
  std::string connection_string_;

 public:
  UserRepository(const std::string& connection_string);
  int MinimalFreeId() const override;
  bool IsUsernameUnique(const std::string&) override;
  void Add(const domain::access::User&) override;
  domain::access::User GetByCredentials(
      const domain::access::Credentials&) override;
  domain::access::User GetById(int) override;
};
}  // namespace postgresadapter

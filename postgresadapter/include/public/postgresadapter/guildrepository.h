#pragma once

#include <string>
#include <vector>

#include "domain/guild/repository.h"

namespace postgresadapter {
class GuildRepository : public domain::guild::Repository {
 private:
  std::string connection_string_;
  std::vector<domain::Guild> guilds_;

 public:
  GuildRepository(const std::string&);
  void Add(const domain::Guild&) override;
  void Remove(const domain::guild::Id&) override;
  std::vector<domain::Guild> GetAll() override;
  domain::Guild& operator[](const domain::guild::Id&) override;
  void Commit() override;
};
}  // namespace postgresadapter

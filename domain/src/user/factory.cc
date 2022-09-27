#include "domain/user/factory.h"

#include <iostream>

#include "domain/character/factory.h"
#include "domain/errors/aliasexistserror.h"

namespace domain {
namespace user {
Factory::Factory(Repository& repository,
                 character::Repository& character_repository)
    : repository_(repository), character_repository_(character_repository) {}
void Factory::CreateUser(const Credentials& credentials) {
  auto id = repository_.MinimalFreeId();
  auto alias = credentials.alias;
  if (!repository_.IsAliasUnique(alias)) throw AliasExistsError();
  std::cout << "Creating user " << credentials.alias.value() << std::endl;
  auto password = credentials.password;
  auto secret = std::string(10, '0');
  for (auto& ch : secret) ch += std::rand() % 10;
  auto user = User(id, alias, password, secret);
  repository_.Add(user);
  auto factory = character::Factory(character_repository_);
  factory.CreateCharacter(user.id(), user.alias());
}
}  // namespace user
}  // namespace domain

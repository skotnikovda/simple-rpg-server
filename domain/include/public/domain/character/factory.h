#pragma once

#include "domain/character.h"
#include "domain/user/alias.h"
#include "domain/user/id.h"
#include "repository.h"

namespace domain {
namespace character {
class Factory {
 private:
  Repository& repository_;

 public:
  Factory(Repository& repository);
  void CreateCharacter(const user::Id&, const user::Alias&);
};
}  // namespace character
}  // namespace domain

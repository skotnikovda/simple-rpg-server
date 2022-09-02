#pragma once

#include "domain/character/repository.h"
#include "repository.h"

namespace domain {
namespace user {
class Factory {
 private:
  Repository& repository_;
  character::Repository& character_repository_;

 public:
  Factory(Repository&, character::Repository&);
  void CreateUser(const Credentials&);
};
}  // namespace user
}  // namespace domain

#pragma once

#include "domain/domainerror.h"

namespace domain {
class AliasExistsError : public DomainError {
 public:
  AliasExistsError() : DomainError("Alias already exists") {}
};
}  // namespace domain

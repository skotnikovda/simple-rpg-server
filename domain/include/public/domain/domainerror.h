#pragma once

#include <stdexcept>

namespace domain {
class DomainError : public std::runtime_error {
 public:
  using std::runtime_error::runtime_error;
};
}  // namespace domain

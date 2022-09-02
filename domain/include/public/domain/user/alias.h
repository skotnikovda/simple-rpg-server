#pragma once

#include <compare>
#include <string>

namespace domain {
namespace user {
class Alias {
 private:
  std::string value_;

 public:
  Alias(const std::string&);
  const std::string& value() const;
  auto operator<=>(const Alias&) const = default;
};
}  // namespace user
}  // namespace domain

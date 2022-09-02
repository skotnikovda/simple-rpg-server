#pragma once

#include <string>

namespace domain {
namespace user {
class Secret {
 private:
  std::string value_;

 public:
  Secret(const std::string&);
  const std::string& value() const;
  auto operator<=>(const Secret&) const = default;
};
}  // namespace user
}  // namespace domain

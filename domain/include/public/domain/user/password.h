#pragma once

#include <string>

namespace domain {
namespace user {
class Password {
 private:
  std::string value_;

 public:
  Password(const std::string&);
  const std::string& value() const;
  auto operator<=>(const Password&) const = default;
};
}  // namespace user
}  // namespace domain

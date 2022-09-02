#pragma once

#include <string>

namespace domain {
namespace character {
class Name {
 private:
  std::string value_;

 public:
  Name(const std::string&);
  const std::string& value() const;
};
}  // namespace character
}  // namespace domain

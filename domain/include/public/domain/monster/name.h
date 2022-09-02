#pragma once

#include <string>

namespace domain {
namespace monster {
class Name {
 private:
  std::string value_;

 public:
  Name(const std::string&);
  std::string value() const;
};
}  // namespace monster
}  // namespace domain

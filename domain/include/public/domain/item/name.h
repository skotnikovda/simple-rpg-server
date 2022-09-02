#pragma once

#include <string>

namespace domain {
namespace item {
class Name {
 private:
  std::string value_;

 public:
  Name(const std::string&);
  std::string value() const;
};
}  // namespace item
}  // namespace domain

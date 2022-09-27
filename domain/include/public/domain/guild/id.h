#pragma once

namespace domain {
namespace guild {
class Id {
 private:
  int value_;

 public:
  explicit Id(int);
  int value() const;
};
}  // namespace guild
}  // namespace domain

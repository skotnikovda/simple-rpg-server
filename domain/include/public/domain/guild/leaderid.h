#pragma once

namespace domain {
namespace guild {
class LeaderId {
 private:
  int value_;

 public:
  LeaderId(int);
  int value() const;
  auto operator<=>(const LeaderId&) const = default;
};
}  // namespace guild
}  // namespace domain

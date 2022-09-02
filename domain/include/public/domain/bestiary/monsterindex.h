#pragma once

namespace domain {
namespace bestiary {
class MonsterIndex {
 private:
  int value_;

 public:
  MonsterIndex(int);
  int value() const;
};
}  // namespace bestiary
}  // namespace domain

#include "ramstorage/userrepository.h"

#include <algorithm>
#include <stdexcept>

namespace ramstorage {
std::vector<domain::User> UserRepository::users_ = {};
domain::user::Id UserRepository::MinimalFreeId() const {
  auto id = int(0);
  for (const auto& user : users_)
    if (user.id() != ++id) break;
  return domain::user::Id(id);
}
bool UserRepository::IsAliasUnique(const domain::user::Alias& alias) const {
  for (const auto& user : users_)
    if (user.alias() == alias) return false;
  return true;
}
void UserRepository::Add(const domain::User& user) {
  if (!IsAliasUnique(user.alias()))
    throw std::runtime_error("User alias duplicates existing user");
  auto id = user.id();
  for (auto& user : users_)
    if (user.id() == id)
      throw std::runtime_error("User id duplicates existing user");
  users_.push_back(user);
  std::sort(users_.begin(), users_.end());
}
domain::User& UserRepository::operator[](const domain::user::Id& id) {
  for (auto& user : users_)
    if (user.id() == id) return user;
  throw std::runtime_error("User not found");
}
const domain::User& UserRepository::operator[](
    const domain::user::Id& id) const {
  for (auto& user : users_)
    if (user.id() == id) return user;
  throw std::runtime_error("User not found");
}
domain::User& UserRepository::operator[](
    const domain::user::Credentials& credentials) {
  for (auto& user : users_)
    if (user.credentials() == credentials) return user;
  throw std::runtime_error("User not found");
}
const domain::User& UserRepository::operator[](
    const domain::user::Credentials& credentials) const {
  for (const auto& user : users_)
    if (user.credentials() == credentials) return user;
  throw std::runtime_error("User not found");
}
}  // namespace ramstorage

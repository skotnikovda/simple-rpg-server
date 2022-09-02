#pragma once

#include "user/accesstoken.h"
#include "user/alias.h"
#include "user/credentials.h"
#include "user/id.h"
#include "user/password.h"
#include "user/secret.h"

namespace domain {
class User {
 private:
  user::Id id_;
  user::Alias alias_;
  user::Password password_;
  user::Secret secret_;

 public:
  User(const user::Id&, const user::Alias&, const user::Password&,
       const user::Secret&);
  const user::Id& id() const;
  const user::Alias& alias() const;
  const user::Password& password() const;
  const user::Secret& secret() const;
  user::Credentials credentials() const;
  user::AccessToken access_token() const;
  auto operator<=>(const User& other) const { return id_ <=> other.id_; }
};
}  // namespace domain

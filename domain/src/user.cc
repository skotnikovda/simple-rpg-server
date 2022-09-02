#include "domain/user.h"

namespace domain {
User::User(const user::Id& id, const user::Alias& alias,
           const user::Password& password, const user::Secret& secret)
    : id_(id), alias_(alias), password_(password), secret_(secret) {}
const user::Id& User::id() const { return id_; }
const user::Alias& User::alias() const { return alias_; }
const user::Password& User::password() const { return password_; }
const user::Secret& User::secret() const { return secret_; }
user::Credentials User::credentials() const { return {alias_, password_}; }
user::AccessToken User::access_token() const { return {id_, secret_}; }
}  // namespace domain

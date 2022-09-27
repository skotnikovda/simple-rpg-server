#include "postgresadapter/userrepository.h"

#include <iostream>
#include <pqxx/pqxx>

namespace postgresadapter {
UserRepository::UserRepository(const std::string& connection_string)
    : connection_string_(connection_string) {}
domain::user::Id UserRepository::MinimalFreeId() const {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row = work.exec1("SELECT MAX(id) + 1 FROM users");
  if (row[0].is_null()) {
    return domain::user::Id(1);
  }
  int minimal_free_id = row[0].as<int>();
  return minimal_free_id;
}
bool UserRepository::IsAliasUnique(const domain::user::Alias& alias) const {
  std::cout << "IsAliasUnique" << std::endl;
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row = work.exec_params1("SELECT COUNT(*) FROM users WHERE alias = $1;",
                               alias.value());
  int count = row[0].as<int>();
  std::cout << "count: " << count << std::endl;
  return count == 0;
}
void UserRepository::Add(const domain::User& user) {
  std::cout << "UserRepository::Add" << std::endl;
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  work.exec_params0(
      "INSERT INTO users (id, alias, password, secret) VALUES ($1, $2, $3, "
      "$4);",
      user.id().value(), user.alias().value(), user.password().value(),
      user.secret().value());
  work.commit();
  std::cout << "UserRepository::Add done" << std::endl;
}
domain::User& UserRepository::operator[](const domain::user::Id& id) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row =
      work.exec_params1("SELECT * FROM users WHERE id = $1;", id.value());
  auto alias = domain::user::Alias(row[1].as<std::string>());
  auto password = domain::user::Password(row[2].as<std::string>());
  auto secret = domain::user::Secret(row[3].as<std::string>());
  auto user = domain::User(id, alias, password, secret);
  users_.push_back(user);
  return users_.back();
}
domain::User& UserRepository::operator[](
    const domain::user::Credentials& credentials) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row = work.exec_params1(
      "SELECT * FROM users WHERE alias = $1 AND password = $2;",
      credentials.alias.value(), credentials.password.value());
  auto id = domain::user::Id(row[0].as<int>());
  auto alias = domain::user::Alias(row[1].as<std::string>());
  auto password = domain::user::Password(row[2].as<std::string>());
  auto secret = domain::user::Secret(row[3].as<std::string>());
  auto user = domain::User(id, alias, password, secret);
  users_.push_back(user);
  return users_.back();
}
void UserRepository::Commit() {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  for (auto& user : users_) {
    work.exec_params1(
        "UPDATE users SET alias = $1, password = $2, secret = $3 WHERE id = "
        "$4;",
        user.alias().value(), user.password().value(), user.secret().value(),
        user.id().value());
  }
  users_.clear();
  work.commit();
}
}  // namespace postgresadapter

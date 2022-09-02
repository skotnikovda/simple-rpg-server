#include "postgresadapter/userrepository.h"

#include <pqxx/pqxx>

namespace postgresadapter {
UserRepository::UserRepository(const std::string& connection_string)
    : connection_string_(connection_string) {}
int UserRepository::MinimalFreeId() const {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row = work.exec1(
      "SELECT MIN(id) FROM users WHERE id > 0 AND id NOT IN "
      "(SELECT id FROM users WHERE id > 0)");
  int minimal_free_id = row[0].as<int>();
  work.commit();
  return minimal_free_id;
}
bool UserRepository::IsUsernameUnique(const std::string& username) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row = work.exec1("SELECT COUNT(*) FROM users WHERE username = '" +
                        username + "'");
  int count = row[0].as<int>();
  work.commit();
  return count == 0;
}
void UserRepository::Add(const domain::access::User& user) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  work.exec1("INSERT INTO users (id, username, password, secret) VALUES (" +
             std::to_string(user.id()) + ", '" + user.username() + ", '" +
             user.password() + "', '" + user.secret() + "')");
  work.commit();
}
domain::access::User UserRepository::GetByCredentials(
    const domain::access::Credentials& credentials) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row = work.exec1(
      "SELECT id, username, password, secret FROM users WHERE username = '" +
      credentials.username + "' AND password = '" + credentials.password + "'");
  int id = row[0].as<int>();
  std::string username = row[1].as<std::string>();
  std::string password = row[2].as<std::string>();
  std::string secret = row[3].as<std::string>();
  work.commit();
  return domain::access::User({id, secret}, {username, password});
}
domain::access::User UserRepository::GetById(int id) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row =
      work.exec1("SELECT username, password, secret FROM users WHERE id = " +
                 std::to_string(id));
  std::string username = row[0].as<std::string>();
  std::string password = row[1].as<std::string>();
  std::string secret = row[2].as<std::string>();
  work.commit();
  return domain::access::User({id, secret}, {username, password});
}
}  // namespace postgresadapter

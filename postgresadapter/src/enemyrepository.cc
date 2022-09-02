#include "postgresadapter/enemyrepository.h"

#include <pqxx/pqxx>

namespace postgresadapter {
EnemyRepository::EnemyRepository(const std::string& connection_string)
    : connection_string_(connection_string) {}
std::vector<domain::game::Enemy> EnemyRepository::GetAll() {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto result = work.exec("SELECT * FROM enemies");
  std::vector<domain::game::Enemy> enemies;
  for (const auto& row : result) {
    auto id = row["id"].as<int>();
    auto name = row["name"].as<std::string>();
    auto level = row["level"].as<int>();
    auto health = row["health"].as<int>();
    auto attack = row["attack"].as<int>();
    auto defense = row["defense"].as<int>();
    auto experience = row["experience"].as<int>();
    auto enemy = domain::game::Enemy(id, name, level, health, attack, defense,
                                     experience);
    enemies.push_back(enemy);
  }
  return enemies;
}
domain::game::Enemy EnemyRepository::GetById(int id) {
  auto connection = pqxx::connection(connection_string_);
  auto transaction = pqxx::transaction(connection);
  auto row = transaction.exec1(
      "SELECT * FROM enemies WHERE id = " + std::to_string(id) + ";");
  auto name = row["name"].as<std::string>();
  auto level = row["level"].as<int>();
  auto health = row["health"].as<int>();
  auto attack = row["attack"].as<int>();
  auto defense = row["defense"].as<int>();
  auto experience = row["experience"].as<int>();
  auto enemy =
      domain::game::Enemy(id, name, level, health, attack, defense, experience);
  return enemy;
}
}  // namespace postgresadapter

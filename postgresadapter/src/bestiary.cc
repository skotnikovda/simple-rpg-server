#include "postgresadapter/bestiary.h"

#include <pqxx/pqxx>

namespace postgresadapter {
Bestiary::Bestiary(const std::string& connection_string) {
  auto connection = pqxx::connection(connection_string);
  auto work = pqxx::work(connection);
  auto result = work.exec("SELECT * FROM monsters");
  for (const auto& monster_row : result) {
    auto id = domain::monster::Id(monster_row["id"].as<int>());
    auto name = domain::monster::Name(monster_row["name"].as<std::string>());
    auto level = domain::Level(monster_row["level"].as<int>());
    auto health = domain::Health(monster_row["health"].as<int>());
    auto attack = domain::Attack(monster_row["attack"].as<int>());
    auto defense = domain::Defense(monster_row["defense"].as<int>());
    auto gold = domain::Gold(monster_row["gold"].as<int>());
    auto experience = domain::Experience(monster_row["experience"].as<int>());
    auto monster = domain::Monster(id, name, level, health, attack, defense,
                                   experience, gold);
    monsters_.push_back(monster);
  }
}
}  // namespace postgresadapter

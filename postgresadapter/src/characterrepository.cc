#include "postgresadapter/characterrepository.h"

#include <iostream>
#include <pqxx/pqxx>

namespace postgresadapter {
CharacterRepository::CharacterRepository(
    const std::string& connection_string,
    const InventoryRepository& inventory_repository,
    const EquipmentRepository& equipment_repository)
    : connection_string_(connection_string),
      inventory_repository_(inventory_repository),
      equipment_repository_(equipment_repository) {}
void CharacterRepository::Add(domain::Character& character) {
  std::cout << "CharacterRepository::Add" << std::endl;
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto id = character.id().value();
  auto name = character.name().value();
  auto experience = character.experience().value();
  auto health = character.health().value();
  auto gold = character.gold().value();
  work.exec_params0(
      "INSERT INTO characters (id, name, experience, health, gold, updated_at) "
      "VALUES ($1, "
      "$2, $3, $4, $5, NOW());",
      id, name, experience, health, gold);
  work.commit();
  std::cout << "CharacterRepository::Add done" << std::endl;
  inventory_repository_.Add(character.inventory());
  equipment_repository_.Add(character.equipment());
}
domain::Character& CharacterRepository::operator[](
    const domain::character::Id& id) {
  for (auto& character : characters_)
    if (character.id() == id) return character;
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto result =
      work.exec_params1("SELECT * FROM characters WHERE id = $1;", id.value());
  auto name = domain::character::Name(result["name"].as<std::string>());
  auto experience = domain::Experience(result["experience"].as<int>());
  auto health = domain::Health(result["health"].as<int>());
  auto gold = domain::Gold(result["gold"].as<int>());
  auto guild_id = std::optional<domain::guild::Id>(std::nullopt);
  if (!result["guild_id"].is_null()) {
    guild_id = domain::guild::Id(result["guild_id"].as<int>());
  }
  auto& inventory = inventory_repository_[id];
  auto& equipment = equipment_repository_[id];
  auto character = domain::Character(id, name, experience, health, inventory,
                                     equipment, gold, guild_id);
  characters_.push_back(character);
  return characters_.back();
}
void CharacterRepository::Commit() {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  for (const auto& character : characters_) {
    auto id = character.id().value();
    auto name = character.name().value();
    auto experience = character.experience().value();
    auto health = character.health().value();
    auto gold = character.gold().value();
    auto guild_id = character.guild_id();
    std::cout << "experience: " << experience << std::endl;
    std::cout << "health: " << health << std::endl;
    std::cout << "gold: " << gold << std::endl;
    if (guild_id.has_value()) {
      std::cout << "guild_id: " << guild_id.value().value() << std::endl;
      work.exec_params0(
          "UPDATE characters SET name = $1, experience = $2, health = $3, "
          "gold = $4, guild_id = $5 WHERE id = $6;",
          name, experience, health, gold, guild_id->value(), id);
    } else {
      std::cout << "guild_id: null" << std::endl;
      work.exec_params0(
          "UPDATE characters SET name = $1, experience = $2, health = $3, "
          "gold = $4, guild_id = NULL WHERE id = $5;",
          name, experience, health, gold, id);
    }
    characters_.clear();
    work.commit();
    inventory_repository_.Commit();
    equipment_repository_.Commit();
  }
}
}  // namespace postgresadapter

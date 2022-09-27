#include "postgresadapter/equipmentrepository.h"

#include <iostream>
#include <pqxx/pqxx>

#include "itemconverter.h"

namespace postgresadapter {
EquipmentRepository::EquipmentRepository(const std::string& connection_string)
    : connection_string_(connection_string) {}
void EquipmentRepository::Add(const domain::Equipment& equipment) {
  std::cout << "EquipmentRepository::Add" << std::endl;
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto id = equipment.id().value();
  work.exec_params0("INSERT INTO equipments (character_id) VALUES ($1);", id);
  work.commit();
  std::cout << "EquipmentRepository::Add done" << std::endl;
}
domain::Equipment& EquipmentRepository::operator[](
    const domain::character::Id& id) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto pg_equipment = work.exec_params1(
      "SELECT * FROM equipments WHERE character_id = $1;", id.value());
  std::map<domain::item::Category, std::optional<domain::Item>> items;
  if (!pg_equipment["helmet_id"].is_null()) {
    auto helmet_id = pg_equipment["helmet_id"].as<int>();
    auto pg_helmet =
        work.exec_params1("SELECT * FROM items WHERE id = $1;", helmet_id);
    auto item = ItemConverter::Convert(pg_helmet);
    items[item.category()] = item;
  }
  if (!pg_equipment["platebody_id"].is_null()) {
    auto platebody_id = pg_equipment["platebody_id"].as<int>();
    auto pg_platebody =
        work.exec_params1("SELECT * FROM items WHERE id = $1;", platebody_id);
    auto item = ItemConverter::Convert(pg_platebody);
    items[item.category()] = item;
  }
  if (!pg_equipment["platelegs_id"].is_null()) {
    auto platelegs_id = pg_equipment["platelegs_id"].as<int>();
    auto pg_platelegs =
        work.exec_params1("SELECT * FROM items WHERE id = $1;", platelegs_id);
    auto item = ItemConverter::Convert(pg_platelegs);
    items[item.category()] = item;
  }
  if (!pg_equipment["boots_id"].is_null()) {
    auto boots_id = pg_equipment["boots_id"].as<int>();
    auto pg_boots =
        work.exec_params1("SELECT * FROM items WHERE id = $1;", boots_id);
    auto item = ItemConverter::Convert(pg_boots);
    items[item.category()] = item;
  }
  if (!pg_equipment["sword_id"].is_null()) {
    auto sword_id = pg_equipment["sword_id"].as<int>();
    auto pg_sword =
        work.exec_params1("SELECT * FROM items WHERE id = $1;", sword_id);
    auto item = ItemConverter::Convert(pg_sword);
    items[item.category()] = item;
  }
  if (!pg_equipment["shield_id"].is_null()) {
    auto shield_id = pg_equipment["shield_id"].as<int>();
    auto pg_shield =
        work.exec_params1("SELECT * FROM items WHERE id = $1;", shield_id);
    auto item = ItemConverter::Convert(pg_shield);
    items[item.category()] = item;
  }
  auto equipment = domain::Equipment(id, items);
  equipments_.push_back(equipment);
  return equipments_.back();
}
void EquipmentRepository::Commit() {
  std::cout << "EquipmentRepository::Commit" << std::endl;
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  for (const auto& equipment : equipments_) {
    auto character_id = equipment.id().value();
    auto helmet = equipment.item(domain::item::Category::Helmet);
    if (helmet) {
      auto helmet_id = helmet->id().value();
      work.exec_params0(
          "UPDATE equipments SET helmet_id = $1 WHERE character_id = $2;",
          helmet_id, character_id);
    } else {
      work.exec_params0(
          "UPDATE equipments SET helmet_id = NULL WHERE character_id = $1;",
          character_id);
    }
    auto platebody = equipment.item(domain::item::Category::Platebody);
    if (platebody) {
      auto platebody_id = platebody->id().value();
      work.exec_params0(
          "UPDATE equipments SET platebody_id = $1 WHERE character_id = $2;",
          platebody_id, character_id);
    } else {
      work.exec_params0(
          "UPDATE equipments SET platebody_id = NULL WHERE character_id = $1;",
          character_id);
    }
    auto platelegs = equipment.item(domain::item::Category::Platelegs);
    if (platelegs) {
      auto platelegs_id = platelegs->id().value();
      work.exec_params0(
          "UPDATE equipments SET platelegs_id = $1 WHERE character_id = $2;",
          platelegs_id, character_id);
    } else {
      work.exec_params0(
          "UPDATE equipments SET platelegs_id = NULL WHERE character_id = $1;",
          character_id);
    }
    auto boots = equipment.item(domain::item::Category::Boots);
    if (boots) {
      auto boots_id = boots->id().value();
      work.exec_params0(
          "UPDATE equipments SET boots_id = $1 WHERE character_id = $2;",
          boots_id, character_id);
    } else {
      work.exec_params0(
          "UPDATE equipments SET boots_id = NULL WHERE character_id = $1;",
          character_id);
    }
    auto sword = equipment.item(domain::item::Category::Sword);
    if (sword) {
      auto sword_id = sword->id().value();
      work.exec_params0(
          "UPDATE equipments SET sword_id = $1 WHERE character_id = $2;",
          sword_id, character_id);
    } else {
      work.exec_params0(
          "UPDATE equipments SET sword_id = NULL WHERE character_id = $1;",
          character_id);
    }
    auto shield = equipment.item(domain::item::Category::Shield);
    if (shield) {
      auto shield_id = shield->id().value();
      work.exec_params0(
          "UPDATE equipments SET shield_id = $1 WHERE character_id = $2;",
          shield_id, character_id);
    } else {
      work.exec_params0(
          "UPDATE equipments SET shield_id = NULL WHERE character_id = $1;",
          character_id);
    }
  }
  equipments_.clear();
  work.commit();
}
}  // namespace postgresadapter

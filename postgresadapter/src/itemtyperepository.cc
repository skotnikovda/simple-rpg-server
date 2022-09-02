#include "postgresadapter/itemtyperepository.h"

#include <pqxx/pqxx>

namespace postgresadapter {
ItemTypeRepository::ItemTypeRepository(const std::string& connection_string)
    : connection_string_(connection_string) {
  shape_map_["sword"] = domain::game::Shape::kSword;
  shape_map_["shield"] = domain::game::Shape::kShield;
  shape_map_["helmet"] = domain::game::Shape::kHelmet;
  shape_map_["platebody"] = domain::game::Shape::kPlatebody;
  shape_map_["platelegs"] = domain::game::Shape::kPlatelegs;
  shape_map_["boots"] = domain::game::Shape::kBoots;
}
std::vector<domain::game::ItemType> ItemTypeRepository::GetAll() {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto result = work.exec("SELECT * FROM itemtype");
  std::vector<domain::game::ItemType> item_types;
  for (const auto& row : result) {
    auto id = row["id"].as<int>();
    auto image = row["image"].as<std::string>();
    auto name = row["name"].as<std::string>();
    auto level = row["level"].as<int>();
    auto attack = row["attack"].as<int>();
    auto defense = row["defense"].as<int>();
    auto shape = shape_map_[row["shape"].as<std::string>()];
    auto buy_price = row["buy_price"].as<int>();
    auto sell_price = row["sell_price"].as<int>();
    auto item_type = domain::game::ItemType(
        id, image, name, level, attack, defense, shape, buy_price, sell_price);
    item_types.push_back(item_type);
  }
  return item_types;
}
domain::game::ItemType ItemTypeRepository::GetById(int id) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row = work.exec1(
      "SELECT * FROM itemtype WHERE id = " + std::to_string(id) + ";");
  auto image = row["image"].as<std::string>();
  auto name = row["name"].as<std::string>();
  auto level = row["level"].as<int>();
  auto attack = row["attack"].as<int>();
  auto defense = row["defense"].as<int>();
  auto shape = shape_map_[row["shape"].as<std::string>()];
  auto buy_price = row["buy_price"].as<int>();
  auto sell_price = row["sell_price"].as<int>();
  auto item_type = domain::game::ItemType(
      id, image, name, level, attack, defense, shape, buy_price, sell_price);
  return item_type;
}
}  // namespace postgresadapter

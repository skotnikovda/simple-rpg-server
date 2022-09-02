#include <pqxx/pqxx>

#include "postgresadapter/characterrepository.h"

namespace postgresadapter {
CharacterRepository::CharacterRepository(const std::string& connection_string)
    : connection_string_(connection_string) {}
domain::game::Character CharacterRepository::GetById(int id) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row =
      work.exec_params1("SELECT id, item_limit FROM characters WHERE id = $1",
                        pqxx::parameter(id));
  auto id = row["id"].as<int>();
  auto item_limit = row["item_limit"].as<int>();
  auto item_rows = work.exe_params(
      "SELECT items.id, image, name, level, attack, defense, "
      "shape, buy_price, sell_price FROM items JOIN item_types ON "
      "items.type_id = item_types.id "
      "WHERE owner_id = $1",
      pqxx::parameter(id));
  std::vector<domain::game::Item> items;
  for (auto row : item_rows) {
    auto id = item["id"].as<int>();
    auto image = item["image"].as<std::string>();
    auto name = item["name"].as<std::string>();
    auto level = item["level"].as<int>();
    auto attack = item["attack"].as<int>();
    auto defense = item["defense"].as<int>();
    auto shape = item["shape"].as<std::string>();
    auto buy_price = item["buy_price"].as<int>();
    auto sell_price = item["sell_price"].as<int>();
    auto item = domain::game::Item(id, image, name, level, attack, defense,
                                   shape, buy_price, sell_price);
    items.push_back(item);
  }
  auto inventory = domain::game::Inventory(item_limit, items);
  return domain::game::Character(id, inventory::Inventory(0, {}),
                                 equipment::Equipment(0, {}));
}
}  // namespace postgresadapter

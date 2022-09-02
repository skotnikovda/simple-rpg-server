#include "postgresadapter/inventoryrepository.h"

#include <pqxx/pqxx>

namespace postgresadapter {
InventoryRepository::InventoryRepository(const std::string& connection_string)
    : connection_string_(connection_string) {}
domain::game::Inventory InventoryRepository::GetByOwnerId(int owner_id) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto row = work.exec_params1(
      "SELECT id, item_limit FROM inventory WHERE owner_id = $1",
      pqxx::vector<pqxx::param>(1, pqxx::param(owner_id)));
  auto id = row[0].as<int>();
  auto item_limit = row[1].as<int>();
  auto result = work.exec_params(
      "SELECT items.id, item_types.id, image, name, level, attack, defense, "
      "shape, buy_price, sell_price FROM items JOIN item_types on item.type_id "
      "= item_types.id WHERE owner_id = $1",
      owner_id);
  std::vector<domain::game::Item> items;
  for (const auto& row : result) {
    auto item_id = row[0].as<int>();
    auto type_id = row[1].as<int>();
    auto image = row[2].as<std::string>();
    auto name = row[3].as<std::string>();
    auto level = row[4].as<int>();
    auto attack = row[5].as<int>();
    auto defense = row[6].as<int>();
    auto shape = row[7].as<std::string>();
    auto buy_price = row[8].as<int>();
    auto sell_price = row[9].as<int>();
    auto item_type =
        domain::game::ItemType(type_id, image, name, level, attack, defense,
                               shape, buy_price, sell_price);
    auto item = domain::game::Item(item_id, item_type);
    items.push_back(item);
  }
  auto inventory = domain::game::Inventory(id, item_limit, items);
  return inventory;
}
}  // namespace postgresadapter

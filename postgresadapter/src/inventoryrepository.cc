#include "postgresadapter/inventoryrepository.h"

#include <iostream>
#include <pqxx/pqxx>

#include "itemconverter.h"

namespace postgresadapter {
InventoryRepository::InventoryRepository(const std::string& connection_string)
    : connection_string_(connection_string) {}
void InventoryRepository::Add(const domain::Inventory& inventory) {
  std::cout << "InventoryRepository::Add" << std::endl;
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto id = inventory.id().value();
  auto size = inventory.size().value();
  work.exec_params0(
      "INSERT INTO inventories (character_id, size, items) VALUES ($1, $2, "
      "'{}');",
      id, size);
  work.commit();
  std::cout << "InventoryRepository::Add done" << std::endl;
}
domain::Inventory& InventoryRepository::operator[](
    const domain::character::Id& id) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto pg_inventory = work.exec_params1(
      "SELECT * FROM inventories WHERE character_id = $1;", id.value());
  auto size = pg_inventory["size"].as<int>();
  auto pg_item_ids = pg_inventory["items"].as<std::string>();
  auto pg_items = work.exec_params(
      "SELECT items.* FROM (SELECT row_number() OVER () AS row_id, ids AS "
      "item_id FROM UNNEST($1::INTEGER[]) AS ids) AS inv JOIN items ON "
      "item_id=items.id ORDER BY row_id;",
      pg_item_ids);
  std::vector<domain::Item> items;
  for (const auto& pg_item : pg_items) {
    auto item = ItemConverter::Convert(pg_item);
    items.push_back(item);
  }
  auto inventory = domain::Inventory(id, size, items);
  inventories_.push_back(inventory);
  return inventories_.back();
}
void InventoryRepository::Commit() {
  std::cout << "InventoryRepository::Commit" << std::endl;
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  for (const auto& inventory : inventories_) {
    auto id = inventory.id().value();
    auto size = inventory.size().value();
    auto item_ids_str = std::string("{");
    for (const auto& item : inventory.items()) {
      item_ids_str += std::to_string(item.id().value()) + ",";
    }
    if (inventory.items().size() > 0) item_ids_str.pop_back();
    item_ids_str += "}";
    std::cout << "item_ids_str " << item_ids_str << std::endl;
    work.exec_params0(
        "UPDATE inventories SET size = $1, items = $2 WHERE character_id = $3;",
        size, item_ids_str, id);
  }
  inventories_.clear();
  work.commit();
}
}  // namespace postgresadapter

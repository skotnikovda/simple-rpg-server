#include "postgresadapter/shop.h"

#include <iostream>
#include <pqxx/pqxx>

#include "itemconverter.h"

namespace postgresadapter {
Shop::Shop(const std::string& connection_string) {
  std::cout << "Connecting to " << connection_string << std::endl;
  auto connection = pqxx::connection(connection_string);
  std::cout << "Connected to " << connection.dbname() << std::endl;
  auto work = pqxx::work(connection);
  auto result = work.exec("SELECT * FROM items");
  for (const auto& item_row : result) {
    auto item = ItemConverter::Convert(item_row);
    items_.push_back(item);
  }
}
}  // namespace postgresadapter

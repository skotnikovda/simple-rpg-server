#include "itemconverter.h"

namespace postgresadapter {
std::map<std::string, domain::item::Category> ItemConverter::map_ = {
    {"helmet", domain::item::Category::Helmet},
    {"platebody", domain::item::Category::Platebody},
    {"platelegs", domain::item::Category::Platelegs},
    {"boots", domain::item::Category::Boots},
    {"sword", domain::item::Category::Sword},
    {"shield", domain::item::Category::Shield}};
domain::Item ItemConverter::Convert(const pqxx::row& pg_item) {
  auto id = domain::item::Id(pg_item["id"].as<int>());
  auto name = domain::item::Name(pg_item["name"].as<std::string>());
  auto level = domain::Level(pg_item["level"].as<int>());
  auto attack = domain::Attack(pg_item["attack"].as<int>());
  auto defense = domain::Defense(pg_item["defense"].as<int>());
  auto category = map_[pg_item["category"].as<std::string>()];
  auto buy_price = domain::item::BuyPrice(pg_item["buy_price"].as<int>());
  auto sell_price = domain::item::SellPrice(pg_item["sell_price"].as<int>());
  return domain::Item(id, name, level, attack, defense, category, buy_price,
                      sell_price);
};
}  // namespace postgresadapter

#include "domain/shop.h"

namespace domain {
Shop::Shop() {
  if (initialized_) return;
  {
    auto name = item::Name("Бронзовый шлем");
    auto level = Level(1);
    auto attack = Attack(0);
    auto defense = Defense(5);
    auto shape = item::Category(domain::item::Category::Helmet);
    auto buy_price = item::BuyPrice(100);
    auto sell_price = item::SellPrice(50);
    auto item =
        Item(name, level, attack, defense, shape, buy_price, sell_price);
    items_.push_back(item);
  }
  initialized_ = true;
}
std::vector<Item> Shop::assortment() const { return items_; }
Item Shop::operator[](const shop::ItemIndex& index) const {
  return items_[index.value()];
}
}  // namespace domain

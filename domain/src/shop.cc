#include "domain/shop.h"

#include "domain/character.h"

namespace domain {
std::vector<Item> Shop::assortment() const { return items_; }
Item Shop::operator[](const shop::ItemIndex& index) const {
  return items_[index.value()];
}
void Shop::AcceptPurchase(Character& character,
                          const shop::ItemIndex& index) const {
  auto item = items_[index.value()];
  character.Take(item);
  character.Give(item.buy_price());
}
void Shop::AcceptSale(Character& character,
                      const inventory::ItemIndex& index) const {
  auto item = character.Give(index);
  character.Take(item.sell_price());
}
}  // namespace domain

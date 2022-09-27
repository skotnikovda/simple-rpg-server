#include "domain/shop/product.h"

namespace domain {
namespace shop {
Product::Product(const Item& item, const BuyPrice& buy_price,
                 const SellPrice& sell_price)
    : item_(item), buy_price_(buy_price), sell_price_(sell_price) {}
Item Product::item() const { return item_; }
BuyPrice Product::buy_price() const { return buy_price_; }
SellPrice Product::sell_price() const { return sell_price_; }
}  // namespace shop
}  // namespace domain

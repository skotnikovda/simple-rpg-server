#include "domain/item.h"

namespace domain {
Item::Item(const item::Id& id, const item::Name& name, const Level& level,
           const Attack& attack, const Defense& defense,
           const item::Category& category, const item::BuyPrice& buy_price,
           const item::SellPrice& sell_price)
    : id_(id),
      name_(name),
      level_(level),
      attack_(attack),
      defense_(defense),
      category_(category),
      buy_price_(buy_price),
      sell_price_(sell_price) {}
item::Id Item::id() const { return id_; }
item::Name Item::name() const { return name_; }
Level Item::level() const { return level_; }
Attack Item::attack() const { return attack_; }
Defense Item::defense() const { return defense_; }
item::Category Item::category() const { return category_; }
item::BuyPrice Item::buy_price() const { return buy_price_; }
item::SellPrice Item::sell_price() const { return sell_price_; }
}  // namespace domain

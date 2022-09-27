#pragma once

#include "domain/properties/attack.h"
#include "domain/properties/defense.h"
#include "domain/properties/level.h"
#include "item/buyprice.h"
#include "item/category.h"
#include "item/id.h"
#include "item/name.h"
#include "item/sellprice.h"

namespace domain {
class Item {
 private:
  item::Id id_;
  item::Name name_;
  Level level_;
  Attack attack_;
  Defense defense_;
  item::Category category_;
  item::BuyPrice buy_price_;
  item::SellPrice sell_price_;

 public:
  Item(const item::Id&, const item::Name&, const Level&, const Attack&,
       const Defense&, const item::Category&, const item::BuyPrice&,
       const item::SellPrice&);
  item::Id id() const;
  item::Name name() const;
  Level level() const;
  Attack attack() const;
  Defense defense() const;
  item::Category category() const;
  item::BuyPrice buy_price() const;
  item::SellPrice sell_price() const;
};
}  // namespace domain

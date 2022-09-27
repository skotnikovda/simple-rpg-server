#include <gtest/gtest.h>

#include <map>
#include <memory>
#include <optional>
#include <string>

#include "domain/character.h"
#include "domain/shop.h"

class CharacterTest : public ::testing::Test {
 protected:
  CharacterTest() {}
  virtual ~CharacterTest() {}

  class Shop : public domain::Shop {
   public:
    Shop(const std::vector<domain::Item>& items) {
      for (const auto& item : items) {
        items_.push_back(item);
      }
    }
  };

  virtual void SetUp() {
    auto id = domain::character::Id(1);
    auto name = domain::character::Name("dummy");
    auto experience = domain::Experience(100);
    auto health = domain::Health(20);
    equiped_helmet = std::make_shared<domain::Item>(
        domain::item::Id(1), domain::item::Name("Bronze Helmet"),
        domain::Level(1), domain::Attack(0), domain::Defense(5),
        domain::item::Category::Helmet, domain::item::BuyPrice(100),
        domain::item::SellPrice(50));
    inventory_item = std::make_shared<domain::Item>(
        domain::item::Id(2), domain::item::Name("Bronze sword"),
        domain::Level(1), domain::Attack(5), domain::Defense(0),
        domain::item::Category::Sword, domain::item::BuyPrice(100),
        domain::item::SellPrice(50));
    auto gold = domain::Gold(100);
    auto size = domain::inventory::Size(5);
    auto items = std::vector<domain::Item>();
    items.push_back(*inventory_item);
    inventory = std::make_shared<domain::Inventory>(id, size, items);
    auto equip_map =
        std::map<domain::item::Category, std::optional<domain::Item>>();
    equip_map[domain::item::Category::Helmet] = *equiped_helmet;
    equipment = std::make_shared<domain::Equipment>(id, equip_map);
    character = std::make_shared<domain::Character>(
        id, name, experience, health, *inventory, *equipment, gold,
        std::nullopt);
    shop_item = std::make_shared<domain::Item>(
        domain::item::Id(3), domain::item::Name("Bronze shield"),
        domain::Level(1), domain::Attack(0), domain::Defense(5),
        domain::item::Category::Shield, domain::item::BuyPrice(100),
        domain::item::SellPrice(50));
    auto shop_items = std::vector<domain::Item>();
    shop_items.push_back(*shop_item);
    shop = std::make_shared<Shop>(shop_items);
  }
  virtual void TearDown() {}

  std::shared_ptr<domain::Character> character;
  std::shared_ptr<domain::Inventory> inventory;
  std::shared_ptr<domain::Equipment> equipment;
  std::shared_ptr<domain::Item> equiped_helmet;
  std::shared_ptr<domain::Item> inventory_item;
  std::shared_ptr<domain::Item> shop_item;
  std::shared_ptr<domain::Shop> shop;
};

TEST_F(CharacterTest, Buy) {
  auto itemIndex = domain::shop::ItemIndex(0);
  character->Buy(itemIndex, *shop);
  EXPECT_EQ(character->gold(), domain::Gold(0));
  EXPECT_EQ(character->inventory().items().size(), 2);
}

TEST_F(CharacterTest, Sell) {
  auto itemIndex = domain::inventory::ItemIndex(0);
  character->Sell(itemIndex, *shop);
  EXPECT_EQ(character->gold(), domain::Gold(150));
  EXPECT_EQ(character->inventory().items().size(), 0);
}

TEST_F(CharacterTest, Equip) {
  auto itemIndex = domain::inventory::ItemIndex(0);
  character->Equip(itemIndex);
  EXPECT_EQ(character->equipment().item(domain::item::Category::Sword)->id(),
            2);
  EXPECT_EQ(character->inventory().items().size(), 0);
}

TEST_F(CharacterTest, Unequip) {
  character->Unequip(domain::item::Category::Helmet);
  EXPECT_EQ(character->inventory().items().size(), 2);
}

TEST_F(CharacterTest, AttackValue) {
  auto itemIndex = domain::inventory::ItemIndex(0);
  character->Equip(itemIndex);
  EXPECT_EQ(character->attack(), domain::Attack(10));
}

TEST_F(CharacterTest, DefenseValue) {
  EXPECT_EQ(character->defense(), domain::Defense(7));
}

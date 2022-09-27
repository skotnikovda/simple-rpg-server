#include "domain/character/factory.h"

#include <iostream>

#include "domain/character/service.h"

namespace domain {
namespace character {
Factory::Factory(Repository& repository) : repository_(repository) {}
void Factory::CreateCharacter(const user::Id& user_id,
                              const user::Alias& alias) {
  std::cout << "Creating character for user " << user_id.value() << std::endl;
  auto id = Id(user_id.value());
  auto name = Name(alias.value());
  auto experience = Experience(100);
  auto service = Service();
  auto health = service.GetMaxBaseHealth(Level(1));
  auto inventory_size = inventory::Size(24);
  auto inventory_items = std::vector<Item>();
  auto inventory = Inventory(id, inventory_size, inventory_items);
  auto equipment = Equipment(id, {});
  auto gold = Gold(1000);
  auto character = Character(id, name, experience, health, inventory, equipment,
                             gold, std::nullopt);
  repository_.Add(character);
}
}  // namespace character
}  // namespace domain

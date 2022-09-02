#include "application/service.h"

#include "application/applicationerror.h"
#include "domain/user/factory.h"

namespace application {
void Service::ValidateAccessToken(
    const domain::user::AccessToken& token) const {
  auto user = (*user_repository)[token.id];
  if (user.secret() != token.secret)
    throw ApplicationError("Invalid access token");
}
void Service::CreateUser(const domain::user::Credentials& credentials) {
  auto factory = domain::user::Factory(*user_repository, *character_repository);
  factory.CreateUser(credentials);
}
domain::user::AccessToken Service::GetAccessToken(
    const domain::user::Credentials& credentials) {
  auto user = (*user_repository)[credentials];
  return user.access_token();
}
domain::Shop Service::GetShop() {
  auto shop = domain::Shop();
  return shop;
}
domain::Bestiary Service::GetBestiary() {
  auto bestiary = domain::Bestiary();
  return bestiary;
}
domain::Inventory Service::GetInventory(
    const domain::user::AccessToken& token) {
  ValidateAccessToken(token);
  auto character_id = domain::character::Id(token.id.value());
  auto character = (*character_repository)[character_id];
  return character.inventory();
}
domain::Equipment Service::GetEquipment(
    const domain::user::AccessToken& token) {
  ValidateAccessToken(token);
  auto character_id = domain::character::Id(token.id.value());
  auto character = (*character_repository)[character_id];
  return character.equipment();
}
void Service::Buy(const application::BuyRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  auto shop = domain::Shop();
  auto item = shop[request.item_index];
  character.Buy(item);
}
void Service::Sell(const application::SellRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  character.Sell(request.item_index);
}
void Service::Equip(const application::EquipRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  character.Equip(request.index);
}
void Service::Unequip(const application::UnequipRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  character.Unequip(request.category);
}
void Service::CreateFight(const application::FightRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  auto bestiary = domain::Bestiary();
  auto monster = bestiary[request.monster_index];
  domain::Fight fight(character, monster);
  last_fight_storage_[character.id()] = fight;
}
domain::Fight Service::GetFight(const domain::user::AccessToken& token) {
  ValidateAccessToken(token);
  auto character_id = domain::character::Id(token.id.value());
  auto fight = last_fight_storage_[character_id];
  if (!fight) throw ApplicationError("No fight found");
  return *fight;
}
}  // namespace application

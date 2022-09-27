#include "application/service.h"

#include <spdlog/spdlog.h>

#include <iostream>

#include "application/applicationerror.h"
#include "domain/user/factory.h"

namespace application {
void Service::ValidateAccessToken(
    const domain::user::AccessToken& token) const {
  auto user = (*user_repository)[token.id];
  if (user.secret() != token.secret) {
    spdlog::error("Invalid access token Expected: {}, {} Actual: {}, {}",
                  token.id.value(), token.secret.value(), user.id().value(),
                  user.secret().value());
    /*
    std::cout << "Invalid access token" << std::endl;
    std::cout << "Expected: " << user.id().value() << " "
              << user.secret().value() << std::endl;
    std::cout << "Got: " << token.id.value() << " " << token.secret.value()
              << std::endl;
              */
    throw ApplicationError("Invalid access token");
  }
}
void Service::CreateUser(const domain::user::Credentials& credentials) {
  spdlog::info("Creating user");
  auto factory = domain::user::Factory(*user_repository, *character_repository);
  // std::cout << "Creating user factory" << std::endl;
  factory.CreateUser(credentials);
}
domain::user::AccessToken Service::GetAccessToken(
    const domain::user::Credentials& credentials) {
  spdlog::info("Getting access token for user {} {}", credentials.alias.value(),
               credentials.password.value());
  auto user = (*user_repository)[credentials];
  return user.access_token();
}
domain::Shop Service::GetShop() {
  spdlog::info("Getting shop");
  return *shop_;
}
domain::Bestiary Service::GetBestiary() {
  spdlog::info("Getting bestiary");
  return *bestiary_;
}
domain::Character Service::GetCharacter(
    const domain::user::AccessToken& token) {
  spdlog::info("Getting character");
  ValidateAccessToken(token);
  auto character_id = domain::character::Id(token.id.value());
  auto character = (*character_repository)[character_id];
  return character;
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
  character.Buy(request.item_index, *shop_);
  character_repository->Commit();
}
void Service::Sell(const application::SellRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  character.Sell(request.item_index, *shop_);
  character_repository->Commit();
}
void Service::Equip(const application::EquipRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  character.Equip(request.index);
  character_repository->Commit();
}
void Service::Unequip(const application::UnequipRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  character.Unequip(request.category);
  character_repository->Commit();
}
void Service::CreateFight(const application::FightRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  auto monster = (*bestiary_)[request.monster_index];
  domain::Fight fight(character, monster);
  last_fight_storage_[character.id()] = fight;
  character_repository->Commit();
}
domain::Fight Service::GetFight(const domain::user::AccessToken& token) {
  ValidateAccessToken(token);
  // std::cout << "Getting fight" << std::endl;
  auto character_id = domain::character::Id(token.id.value());
  auto fight = last_fight_storage_[character_id];
  // std::cout << "Got fight" << std::endl;
  if (!fight) throw ApplicationError("No fight found");
  return *fight;
}
std::vector<domain::Guild> Service::GetGuilds() {
  return guild_repository->GetAll();
}
domain::Guild Service::GetGuild(const domain::guild::Id& id) {
  return (*guild_repository)[id];
}
void Service::CreateGuild(const application::CreateGuildRequest& request) {
  ValidateAccessToken(request.token);
  // std::cout << "Creating guild" << std::endl;
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  auto leader_id = domain::guild::LeaderId(character.id().value());
  auto id = domain::guild::Id(character.id().value());
  auto guild = domain::Guild(id, request.name, leader_id, {});
  guild.AddMember(character);
  character.JoinGuild(guild);
  // std::cout << "Adding guild" << std::endl;
  guild_repository->Add(guild);
  // std::cout << "Committing" << std::endl;
  character_repository->Commit();
}
void Service::JoinGuild(const application::JoinGuildRequest& request) {
  ValidateAccessToken(request.token);
  auto character_id = domain::character::Id(request.token.id.value());
  auto& character = (*character_repository)[character_id];
  auto& guild = (*guild_repository)[request.id];
  guild.AddMember(character);
  character.JoinGuild(guild);
  guild_repository->Commit();
  character_repository->Commit();
}
void Service::LeaveGuild(const domain::user::AccessToken& token) {
  ValidateAccessToken(token);
  auto character_id = domain::character::Id(token.id.value());
  auto& character = (*character_repository)[character_id];
  auto id = *character.guild_id();
  auto& guild = (*guild_repository)[id];
  if (guild.leader_id() == domain::guild::LeaderId(character.id().value())) {
    character_repository->Commit();
    guild_repository->Remove(guild.id());
    return;
  }
  character.LeaveGuild();
  character_repository->Commit();
}
void Service::Heal(const domain::user::AccessToken& token) {
  ValidateAccessToken(token);
  auto character_id = domain::character::Id(token.id.value());
  auto& character = (*character_repository)[character_id];
  auto max_health = character.max_health();
  auto current_health = character.health();
  auto health_to_heal =
      domain::Health(max_health.value() - current_health.value());
  character.Heal(health_to_heal);
  character_repository->Commit();
}
}  // namespace application

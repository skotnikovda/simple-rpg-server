#pragma once

#include <memory>

#include "application/requests/buyrequest.h"
#include "application/requests/createguildrequest.h"
#include "application/requests/equiprequest.h"
#include "application/requests/fightrequest.h"
#include "application/requests/joinguildrequest.h"
#include "application/requests/sellrequest.h"
#include "application/requests/unequiprequest.h"
#include "domain/bestiary.h"
#include "domain/character/repository.h"
#include "domain/fight.h"
#include "domain/guild.h"
#include "domain/guild/repository.h"
#include "domain/shop.h"
#include "domain/user/repository.h"
#include "lastfightstorage.h"

namespace application {
class Service {
 private:
  void ValidateAccessToken(const domain::user::AccessToken& token) const;
  LastFightStorage last_fight_storage_;

 public:
  std::shared_ptr<domain::user::Repository> user_repository;
  std::shared_ptr<domain::character::Repository> character_repository;
  std::shared_ptr<domain::guild::Repository> guild_repository;
  std::shared_ptr<domain::Shop> shop_;
  std::shared_ptr<domain::Bestiary> bestiary_;
  void CreateUser(const domain::user::Credentials&);
  domain::user::AccessToken GetAccessToken(const domain::user::Credentials&);
  domain::Shop GetShop();
  domain::Bestiary GetBestiary();
  domain::Character GetCharacter(const domain::user::AccessToken&);
  domain::Inventory GetInventory(const domain::user::AccessToken&);
  domain::Equipment GetEquipment(const domain::user::AccessToken&);
  void Buy(const BuyRequest&);
  void Sell(const SellRequest&);
  void Equip(const EquipRequest&);
  void Unequip(const UnequipRequest&);
  void CreateFight(const FightRequest&);
  domain::Fight GetFight(const domain::user::AccessToken&);
  std::vector<domain::Guild> GetGuilds();
  domain::Guild GetGuild(const domain::guild::Id&);
  void CreateGuild(const CreateGuildRequest&);
  void JoinGuild(const JoinGuildRequest&);
  void LeaveGuild(const domain::user::AccessToken&);
  void Heal(const domain::user::AccessToken&);
};
}  // namespace application

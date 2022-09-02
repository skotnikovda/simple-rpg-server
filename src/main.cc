#include <iostream>

#include "application/registry.h"
#include "httpadapter/actions/accesstokengetter.h"
#include "httpadapter/actions/bestiarygetter.h"
#include "httpadapter/actions/buyer.h"
#include "httpadapter/actions/equiper.h"
#include "httpadapter/actions/equipmentgetter.h"
#include "httpadapter/actions/fightcreator.h"
#include "httpadapter/actions/fightgetter.h"
#include "httpadapter/actions/inventorygetter.h"
#include "httpadapter/actions/seller.h"
#include "httpadapter/actions/shopgetter.h"
#include "httpadapter/actions/unequiper.h"
#include "httpadapter/actions/usercreator.h"
#include "httpadapter/boost/server.h"
#include "httpadapter/boost/serverfactory.h"
#include "httpadapter/core/frontcontroller.h"
#include "ramstorage/characterrepository.h"
#include "ramstorage/userrepository.h"

const std::string postres = "postgres://postgres:1234@localhost:5432";

int main() {
  std::cout << "Hello, World!" << std::endl;
  auto service = std::make_shared<application::Service>();
  auto user_repository = std::make_shared<ramstorage::UserRepository>();
  service->user_repository = user_repository;
  auto character_repository =
      std::make_shared<ramstorage::CharacterRepository>();
  service->character_repository = character_repository;
  application::Registry::SetService(service);
  httpadapter::FrontController controller;
  controller.RegisterAction<httpadapter::AccessTokenGetter>();
  controller.RegisterAction<httpadapter::BestiaryGetter>();
  controller.RegisterAction<httpadapter::Buyer>();
  controller.RegisterAction<httpadapter::Equiper>();
  controller.RegisterAction<httpadapter::EquipmentGetter>();
  controller.RegisterAction<httpadapter::FightCreator>();
  controller.RegisterAction<httpadapter::FightGetter>();
  controller.RegisterAction<httpadapter::InventoryGetter>();
  controller.RegisterAction<httpadapter::Seller>();
  controller.RegisterAction<httpadapter::ShopGetter>();
  controller.RegisterAction<httpadapter::Unequiper>();
  controller.RegisterAction<httpadapter::UserCreator>();
  auto factory = httpadapter::ServerFactory();
  auto server = factory.Create<httpadapter::Server>(controller, "8080", "4");
  server.Run();
  std::cout << "Bye, World!" << std::endl;
  return 0;
}

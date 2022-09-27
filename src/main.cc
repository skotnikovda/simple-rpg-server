#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/actions/accesstokengetter.h"
#include "httpadapter/actions/bestiarygetter.h"
#include "httpadapter/actions/buyer.h"
#include "httpadapter/actions/charactergetter.h"
#include "httpadapter/actions/equiper.h"
#include "httpadapter/actions/equipmentgetter.h"
#include "httpadapter/actions/fightcreator.h"
#include "httpadapter/actions/fightgetter.h"
#include "httpadapter/actions/guildcreator.h"
#include "httpadapter/actions/guildgetter.h"
#include "httpadapter/actions/guildjoiner.h"
#include "httpadapter/actions/guildleaver.h"
#include "httpadapter/actions/guildlistgetter.h"
#include "httpadapter/actions/healer.h"
#include "httpadapter/actions/inventorygetter.h"
#include "httpadapter/actions/seller.h"
#include "httpadapter/actions/shopgetter.h"
#include "httpadapter/actions/unequiper.h"
#include "httpadapter/actions/usercreator.h"
#include "httpadapter/boost/server.h"
#include "httpadapter/boost/serverfactory.h"
#include "httpadapter/core/frontcontroller.h"
#include "postgresadapter/bestiary.h"
#include "postgresadapter/characterrepository.h"
#include "postgresadapter/guildrepository.h"
#include "postgresadapter/shop.h"
#include "postgresadapter/userrepository.h"

static std::string postgres = "";

int main() {
  std::cout << "Hello, World!" << std::endl;
  try {
    auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
    spdlog::set_default_logger(logger);
    spdlog::flush_on(spdlog::level::info);
  } catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
    return 0;
  }
  std::ifstream file("config.json");
  nlohmann::json config = nlohmann::json::parse(file);
  postgres = config["postgres"];
  auto service = std::make_shared<application::Service>();
  std::cout << "Service created" << std::endl;
  auto user_repository =
      std::make_shared<postgresadapter::UserRepository>(postgres);
  std::cout << "User repository created" << std::endl;
  service->user_repository = user_repository;
  auto inventory_repository = postgresadapter::InventoryRepository(postgres);
  std::cout << "Inventory repository created" << std::endl;
  auto equipment_repository = postgresadapter::EquipmentRepository(postgres);
  std::cout << "Equipment repository created" << std::endl;
  auto character_repository =
      std::make_shared<postgresadapter::CharacterRepository>(
          postgres, inventory_repository, equipment_repository);
  std::cout << "Character repository created" << std::endl;
  service->character_repository = character_repository;
  std::cout << "Character repository set" << std::endl;
  auto guild_repository =
      std::make_shared<postgresadapter::GuildRepository>(postgres);
  std::cout << "Guild repository created" << std::endl;
  service->guild_repository = guild_repository;
  std::cout << "Guild repository set" << std::endl;
  auto shop = std::make_shared<postgresadapter::Shop>(postgres);
  std::cout << "Shop created" << std::endl;
  service->shop_ = shop;
  auto bestiary = std::make_shared<postgresadapter::Bestiary>(postgres);
  std::cout << "Bestiary created" << std::endl;
  service->bestiary_ = bestiary;

  application::Registry::SetService(service);
  std::cout << "Service registered" << std::endl;
  httpadapter::FrontController controller;
  controller.RegisterAction<httpadapter::AccessTokenGetter>();
  controller.RegisterAction<httpadapter::BestiaryGetter>();
  controller.RegisterAction<httpadapter::Buyer>();
  controller.RegisterAction<httpadapter::CharacterGetter>();
  controller.RegisterAction<httpadapter::Equiper>();
  controller.RegisterAction<httpadapter::EquipmentGetter>();
  controller.RegisterAction<httpadapter::FightCreator>();
  controller.RegisterAction<httpadapter::FightGetter>();
  controller.RegisterAction<httpadapter::GuildCreator>();
  controller.RegisterAction<httpadapter::GuildGetter>();
  controller.RegisterAction<httpadapter::GuildJoiner>();
  controller.RegisterAction<httpadapter::GuildLeaver>();
  controller.RegisterAction<httpadapter::GuildListGetter>();
  controller.RegisterAction<httpadapter::Healer>();
  controller.RegisterAction<httpadapter::InventoryGetter>();
  controller.RegisterAction<httpadapter::Seller>();
  controller.RegisterAction<httpadapter::ShopGetter>();
  controller.RegisterAction<httpadapter::Unequiper>();
  controller.RegisterAction<httpadapter::UserCreator>();

  auto factory = httpadapter::ServerFactory();
  auto server = factory.Create<httpadapter::Server>(controller, "8080", "1");
  std::cout << "Server started" << std::endl;
  server.Run();
  std::cout << "Bye, World!" << std::endl;
  return 0;
}

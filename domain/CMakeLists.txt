cmake_minimum_required(VERSION 3.16)
project(domain)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
  ${PROJECT_NAME} STATIC
  include/public/domain/bestiary.h
  include/public/domain/bestiary/monsterindex.h
  include/public/domain/character.h
  include/public/domain/character/factory.h
  include/public/domain/character/id.h
  include/public/domain/character/name.h
  include/public/domain/character/repository.h
  include/public/domain/character/service.h
  include/public/domain/domainerror.h
  include/public/domain/equipment.h
  include/public/domain/errors/aliasexistserror.h
  include/public/domain/experience.h
  include/public/domain/fight.h
  include/public/domain/fight/actor.h
  include/public/domain/fight/damage.h
  include/public/domain/fight/event.h
  include/public/domain/gold.h
  include/public/domain/inventory.h
  include/public/domain/inventory/itemcount.h
  include/public/domain/inventory/itemindex.h
  include/public/domain/inventory/size.h
  include/public/domain/item.h
  include/public/domain/item/buyprice.h
  include/public/domain/item/category.h
  include/public/domain/item/name.h
  include/public/domain/item/sellprice.h
  include/public/domain/monster.h
  include/public/domain/monster/name.h
  include/public/domain/properties/attack.h
  include/public/domain/properties/defense.h
  include/public/domain/properties/health.h
  include/public/domain/properties/level.h
  include/public/domain/shop.h
  include/public/domain/shop/itemindex.h
  include/public/domain/user.h
  include/public/domain/user/accesstoken.h
  include/public/domain/user/alias.h
  include/public/domain/user/credentials.h
  include/public/domain/user/factory.h
  include/public/domain/user/id.h
  include/public/domain/user/password.h
  include/public/domain/user/repository.h
  include/public/domain/user/secret.h
  src/bestiary.cc
  src/bestiary/monsterindex.cc
  src/character.cc
  src/character/factory.cc
  src/character/id.cc
  src/character/name.cc
  src/character/service.cc
  src/equipment.cc
  src/experience.cc
  src/fight.cc
  src/fight/damage.cc
  src/fight/event.cc
  src/gold.cc
  src/inventory.cc
  src/inventory/itemcount.cc
  src/inventory/itemindex.cc
  src/inventory/size.cc
  src/item.cc
  src/item/name.cc
  src/monster.cc
  src/monster/name.cc
  src/properties/attack.cc
  src/properties/defense.cc
  src/properties/health.cc
  src/properties/level.cc
  src/shop.cc
  src/shop/itemindex.cc
  src/user.cc
  src/user/alias.cc
  src/user/factory.cc
  src/user/id.cc
  src/user/password.cc
  src/user/secret.cc)

target_include_directories(${PROJECT_NAME} PUBLIC include/public)

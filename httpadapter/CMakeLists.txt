cmake_minimum_required(VERSION 3.16)
project(httpadapter)

set(CMAKE_CXX_STANDARD 20)

add_library(
  ${PROJECT_NAME} STATIC
  include/public/httpadapter/actions/accesstokengetter.h
  include/public/httpadapter/actions/bestiarygetter.h
  include/public/httpadapter/actions/buyer.h
  include/public/httpadapter/actions/equiper.h
  include/public/httpadapter/actions/equipmentgetter.h
  include/public/httpadapter/actions/fightcreator.h
  include/public/httpadapter/actions/fightgetter.h
  include/public/httpadapter/actions/inventorygetter.h
  include/public/httpadapter/actions/seller.h
  include/public/httpadapter/actions/shopgetter.h
  include/public/httpadapter/actions/unequiper.h
  include/public/httpadapter/actions/usercreator.h
  include/public/httpadapter/boost/iocontext.h
  include/public/httpadapter/boost/listener.h
  include/public/httpadapter/boost/server.h
  include/public/httpadapter/boost/serverfactory.h
  include/public/httpadapter/boost/session.h
  include/public/httpadapter/boost/sessionfactory.h
  include/public/httpadapter/concepts/serverconcept.h
  include/public/httpadapter/converters/accesstoken.h
  include/public/httpadapter/converters/bestiary.h
  include/public/httpadapter/converters/buyrequest.h
  include/public/httpadapter/converters/credentials.h
  include/public/httpadapter/converters/equipment.h
  include/public/httpadapter/converters/equiprequest.h
  include/public/httpadapter/converters/fight.h
  include/public/httpadapter/converters/fightactor.h
  include/public/httpadapter/converters/fightevent.h
  include/public/httpadapter/converters/fightrequest.h
  include/public/httpadapter/converters/inventory.h
  include/public/httpadapter/converters/item.h
  include/public/httpadapter/converters/itemcategory.h
  include/public/httpadapter/converters/monster.h
  include/public/httpadapter/converters/sellrequest.h
  include/public/httpadapter/converters/shop.h
  include/public/httpadapter/converters/unequiprequest.h
  include/public/httpadapter/core/concepts/constructibleto.h
  include/public/httpadapter/core/concepts/convertiblefrom.h
  include/public/httpadapter/core/concepts/getresponding.h
  include/public/httpadapter/core/concepts/postresponding.h
  include/public/httpadapter/core/concepts/targeted.h
  include/public/httpadapter/core/frontcontroller.h
  include/public/httpadapter/core/handler.h
  include/public/httpadapter/core/method.h
  include/public/httpadapter/core/request.h
  include/public/httpadapter/core/response.h
  include/public/httpadapter/core/target.h
  include/public/httpadapter/utility/defaultresponse.h
  include/public/httpadapter/utility/requesthandler.h
  src/actions/accesstokengetter.cc
  src/actions/bestiarygetter.cc
  src/actions/buyer.cc
  src/actions/equiper.cc
  src/actions/equipmentgetter.cc
  src/actions/fightcreator.cc
  src/actions/fightgetter.cc
  src/actions/inventorygetter.cc
  src/actions/seller.cc
  src/actions/shopgetter.cc
  src/actions/unequiper.cc
  src/actions/usercreator.cc
  src/converters/accesstoken.cc
  src/converters/bestiary.cc
  src/converters/buyrequest.cc
  src/converters/credentials.cc
  src/converters/equipment.cc
  src/converters/equiprequest.cc
  src/converters/fight.cc
  src/converters/fightactor.cc
  src/converters/fightevent.cc
  src/converters/fightrequest.cc
  src/converters/inventory.cc
  src/converters/item.cc
  src/converters/itemcategory.cc
  src/converters/monster.cc
  src/converters/sellrequest.cc
  src/converters/shop.cc
  src/converters/unequiprequest.cc
  src/utility/defaultresponse.cc
  src/utility/requesthandler.cc)

target_include_directories(${PROJECT_NAME} PUBLIC include/public)

find_package(Boost REQUIRED)
find_package(Threads REQUIRED)
add_subdirectory(lib/json)

target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(
  ${PROJECT_NAME} PUBLIC ${Boost_LIBRARIES} Threads::Threads
                         nlohmann_json::nlohmann_json)

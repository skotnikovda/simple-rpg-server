cmake_minimum_required(VERSION 3.16)
project(postgresadapter)

set(CMAKE_CXX_STANDARD 20)

add_library(
  ${PROJECT_NAME} STATIC
  include/private/itemconverter.h
  include/public/postgresadapter/bestiary.h
  include/public/postgresadapter/characterrepository.h
  include/public/postgresadapter/equipmentrepository.h
  include/public/postgresadapter/guildrepository.h
  include/public/postgresadapter/inventoryrepository.h
  include/public/postgresadapter/shop.h
  include/public/postgresadapter/userrepository.h
  src/bestiary.cc
  src/characterrepository.cc
  src/equipmentrepository.cc
  src/guildrepository.cc
  src/inventoryrepository.cc
  src/itemconverter.cc
  src/shop.cc
  src/userrepository.cc)

target_include_directories(${PROJECT_NAME} PUBLIC include/public)
target_include_directories(${PROJECT_NAME} PRIVATE include/private)

add_subdirectory(lib/libpqxx)
target_link_libraries(${PROJECT_NAME} PUBLIC pqxx)

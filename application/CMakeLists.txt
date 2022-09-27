cmake_minimum_required(VERSION 3.16)
project(application)

set(CMAKE_CXX_STANDARD 20)

add_library(
  ${PROJECT_NAME} STATIC
  include/public/application/applicationerror.h
  include/public/application/lastfightstorage.h
  include/public/application/registry.h
  include/public/application/requests/buyrequest.h
  include/public/application/requests/createguildrequest.h
  include/public/application/requests/equiprequest.h
  include/public/application/requests/fightrequest.h
  include/public/application/requests/joinguildrequest.h
  include/public/application/requests/sellrequest.h
  include/public/application/requests/unequiprequest.h
  include/public/application/service.h
  src/registry.cc
  src/service.cc)

target_include_directories(${PROJECT_NAME} PUBLIC include/public)

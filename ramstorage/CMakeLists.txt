cmake_minimum_required(VERSION 3.17)
project(ramstorage)

add_library(
  ${PROJECT_NAME} STATIC
  include/public/ramstorage/characterrepository.h
  include/public/ramstorage/userrepository.h src/characterrepository.cc
  src/userrepository.cc)

target_include_directories(${PROJECT_NAME} PUBLIC include/public)

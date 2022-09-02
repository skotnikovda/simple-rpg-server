cmake_minimum_required(VERSION 3.16)
project(postgresadapter)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME}
    STATIC
    include/public/postgresadapter/enemyrepository.h
    include/public/postgresadapter/inventoryrepository.h
    include/public/postgresadapter/itemtyperepository.h
    include/public/postgresadapter/userrepository.h
    src/enemyrepository.cc
    src/inventoryrepository.cc
    src/itemtyperepository.cc
    src/userrepository.cc
)

target_include_directories(${PROJECT_NAME} PUBLIC include/public)

add_subdirectory(lib/libpqxx)
target_link_libraries(${PROJECT_NAME} PUBLIC pqxx)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_C_COMPILER "gcc-12") set(CMAKE_CXX_COMPILER "g++-12")

project(server)

add_executable(${PROJECT_NAME} src/main.cc)

add_subdirectory(application)
add_subdirectory(domain)
add_subdirectory(httpadapter)
add_subdirectory(postgresadapter)
# add_subdirectory(ramstorage)

target_link_libraries(application PUBLIC domain)
target_link_libraries(httpadapter PUBLIC application)
target_link_libraries(postgresadapter PUBLIC application)
# target_link_libraries(ramstorage PUBLIC application)
target_link_libraries(${PROJECT_NAME} PUBLIC httpadapter postgresadapter)
# target_link_libraries(${PROJECT_NAME} PUBLIC httpadapter ramstorage)

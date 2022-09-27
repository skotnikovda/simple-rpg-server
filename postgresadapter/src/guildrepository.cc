#include "postgresadapter/guildrepository.h"

#include <iostream>
#include <pqxx/pqxx>

namespace postgresadapter {
GuildRepository::GuildRepository(const std::string& connection_string)
    : connection_string_(connection_string) {}
void GuildRepository::Add(const domain::Guild& guild) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  work.exec_params0(
      "INSERT INTO guilds (id, name, leader_id) VALUES ($1, $2, $3)",
      guild.id().value(), guild.name().value(), guild.leader_id().value());
  work.commit();
  std::cout << "Added guild" << std::endl;
}
void GuildRepository::Remove(const domain::guild::Id& id) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  work.exec_params0(
      "UPDATE characters set guild_id = null WHERE guild_id = $1; DELETE FROM "
      "guilds WHERE id = $1;",
      id.value());
  work.commit();
  std::cout << "Removed guild" << std::endl;
}
std::vector<domain::Guild> GuildRepository::GetAll() {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto pg_guilds = work.exec("SELECT * FROM guilds");
  auto guilds = std::vector<domain::Guild>();
  for (const auto& pg_guild : pg_guilds) {
    auto id = domain::guild::Id(pg_guild["id"].as<int>());
    auto name = domain::guild::Name(pg_guild["name"].as<std::string>());
    auto leader_id = domain::guild::LeaderId(pg_guild["leader_id"].as<int>());
    auto members = std::vector<domain::guild::Member>();
    auto pg_members = work.exec_params(
        "SELECT id, name, experience FROM characters WHERE guild_id = $1;",
        id.value());
    for (const auto& pg_member : pg_members) {
      auto id = domain::character::Id(pg_member["id"].as<int>());
      auto name = domain::character::Name(pg_member["name"].as<std::string>());
      auto experience = domain::Experience(pg_member["experience"].as<int>());
      auto member = domain::guild::Member(id, name, experience);
      members.push_back(member);
    }
    auto guild = domain::Guild(id, name, leader_id, members);
    guilds.push_back(guild);
  }
  return guilds;
}
domain::Guild& GuildRepository::operator[](const domain::guild::Id& id) {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  auto pg_guild =
      work.exec_params1("SELECT * FROM guilds WHERE id = $1;", id.value());
  auto name = domain::guild::Name(pg_guild["name"].as<std::string>());
  auto leader_id = domain::guild::LeaderId(pg_guild["leader_id"].as<int>());
  auto members = std::vector<domain::guild::Member>();
  auto pg_members = work.exec_params(
      "SELECT id, name, experience FROM characters WHERE guild_id = $1;",
      id.value());
  for (const auto& pg_member : pg_members) {
    auto id = domain::character::Id(pg_member["id"].as<int>());
    auto name = domain::character::Name(pg_member["name"].as<std::string>());
    auto experience = domain::Experience(pg_member["experience"].as<int>());
    auto member = domain::guild::Member(id, name, experience);
    members.push_back(member);
  }
  auto guild = domain::Guild(id, name, leader_id, members);
  guilds_.push_back(guild);
  return guilds_.back();
}
void GuildRepository::Commit() {
  auto connection = pqxx::connection(connection_string_);
  auto work = pqxx::work(connection);
  for (const auto& guild : guilds_) {
    work.exec_params0(
        "UPDATE guilds SET name = $1, leader_id = $2 WHERE id = $3;",
        guild.name().value(), guild.leader_id().value(), guild.id().value());
    for (const auto& member : guild.members()) {
      work.exec_params("UPDATE characters SET guild_id = $1 WHERE id = $2;",
                       guild.id().value(), member.id().value());
    }
  }
  guilds_.clear();
  work.commit();
}
}  // namespace postgresadapter

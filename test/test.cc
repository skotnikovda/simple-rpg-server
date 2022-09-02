#include <cstdlib>

#include "application/service.h"
#include "ramstorage/enemy_repository.h"

domain::EnemyType CreateEnemyType() {
  auto id = domain::Id(1);
  auto name = domain::Name("enemy");
  auto level = domain::Level(1);
  auto health = domain::Health(30);
  auto attack = domain::Attack(1);
  auto defense = domain::Defense(0);
  auto experience = domain::Experience(1);
  auto enemy_type =
      domain::EnemyType(id, name, level, health, attack, defense, experience);
  return enemy_type;
}

int main() {
  auto enemy_repository = std::make_shared<ramstorage::EnemyRepository>();
  enemy_repository->Add(CreateEnemyType());
  auto service = application::Service();
  auto credentials = domain::access::Credentials("username", "password");
  service.identify(credentials);
  auto access_token = service.GetAccessToken(credentials);
  auto enemies = service.GetEnemies();
  auto enemy = enemies[0];
  return EXIT_SUCCESS;
}

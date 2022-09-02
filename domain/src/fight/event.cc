#include "domain/fight/event.h"

namespace domain {
namespace fight {
Event::Event(const Actor& actor, const Damage& damage)
    : actor_(actor), damage_(damage) {}
Actor Event::actor() const { return actor_; }
Damage Event::damage() const { return damage_; }
}  // namespace fight
}  // namespace domain

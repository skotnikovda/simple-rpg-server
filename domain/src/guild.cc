#include "domain/guild.h"

namespace domain {
Guild::Guild(const guild::Id& id, const guild::Name& name,
             const guild::LeaderId& leader_id,
             const std::vector<guild::Member>& members)
    : id_(id), name_(name), leader_id_(leader_id), members_(members) {}
guild::Id Guild::id() const { return id_; }
guild::Name Guild::name() const { return name_; }
guild::LeaderId Guild::leader_id() const { return leader_id_; }
std::vector<guild::Member> Guild::members() const { return members_; }
void Guild::AddMember(const guild::Member& member) {
  members_.push_back(member);
}
}  // namespace domain

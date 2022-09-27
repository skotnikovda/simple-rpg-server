#pragma once

#include <vector>

#include "guild/id.h"
#include "guild/leaderid.h"
#include "guild/member.h"
#include "guild/name.h"

namespace domain {
class Guild {
 private:
  guild::Id id_;
  guild::Name name_;
  guild::LeaderId leader_id_;
  std::vector<guild::Member> members_;

 public:
  Guild(const guild::Id&, const guild::Name&, const guild::LeaderId&,
        const std::vector<guild::Member>&);
  guild::Id id() const;
  guild::Name name() const;
  guild::LeaderId leader_id() const;
  std::vector<guild::Member> members() const;
  void AddMember(const guild::Member&);
};
}  // namespace domain

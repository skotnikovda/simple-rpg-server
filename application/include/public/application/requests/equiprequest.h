#pragma once

#include "domain/inventory/itemindex.h"
#include "domain/user/accesstoken.h"

namespace application {
struct EquipRequest {
  domain::user::AccessToken token;
  domain::inventory::ItemIndex index;
};
}  // namespace application

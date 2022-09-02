#pragma once

#include "domain/inventory/itemindex.h"
#include "domain/user/accesstoken.h"

namespace application {
struct SellRequest {
  domain::user::AccessToken token;
  domain::inventory::ItemIndex item_index;
};
}  // namespace application

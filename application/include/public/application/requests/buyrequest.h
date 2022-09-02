#pragma once

#include "domain/shop/itemindex.h"
#include "domain/user/accesstoken.h"

namespace application {
struct BuyRequest {
  domain::user::AccessToken token;
  domain::shop::ItemIndex item_index;
};
}  // namespace application

#pragma once

#include "domain/item/category.h"
#include "domain/user/accesstoken.h"

namespace application {
struct UnequipRequest {
  domain::user::AccessToken token;
  domain::item::Category category;
};
}  // namespace application

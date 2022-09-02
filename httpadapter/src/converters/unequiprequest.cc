#include "httpadapter/converters/unequiprequest.h"

#include "httpadapter/converters/accesstoken.h"
#include "httpadapter/converters/itemcategory.h"

namespace httpadapter {
application::UnequipRequest UnequipRequest::ToType(const nlohmann::json& data) {
  auto access_token = AccessToken::ToType(data);
  auto category = ItemCategory::ToType(data["category"]);
  return application::UnequipRequest{access_token, category};
}
}  // namespace httpadapter

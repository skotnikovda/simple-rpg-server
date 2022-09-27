#include "httpadapter/converters/buyrequest.h"

#include "httpadapter/converters/accesstoken.h"

namespace httpadapter {
application::BuyRequest BuyRequest::ToType(const nlohmann::json& data) {
  auto access_token = AccessToken::ToType(data["access_token"]);
  auto item_index = domain::shop::ItemIndex(data["item_index"].get<int>());
  return application::BuyRequest(access_token, item_index);
}
}  // namespace httpadapter

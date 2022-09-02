#include "httpadapter/converters/sellrequest.h"

#include "httpadapter/converters/accesstoken.h"

namespace httpadapter {
application::SellRequest SellRequest::ToType(const nlohmann::json& data) {
  auto access_token = AccessToken::ToType(data);
  auto item_index = domain::inventory::ItemIndex(data["item_index"].get<int>());
  return application::SellRequest(access_token, item_index);
}
}  // namespace httpadapter

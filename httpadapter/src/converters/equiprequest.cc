#include "httpadapter/converters/equiprequest.h"

#include "httpadapter/converters/accesstoken.h"

namespace httpadapter {
application::EquipRequest EquipRequest::ToType(const nlohmann::json& data) {
  auto access_token = AccessToken::ToType(data["access_token"]);
  auto item_index = domain::inventory::ItemIndex(data["item_index"].get<int>());
  return application::EquipRequest{access_token, item_index};
}
}  // namespace httpadapter

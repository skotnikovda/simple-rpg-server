#pragma once

#include <nlohmann/json.hpp>

#include "application/requests/buyrequest.h"

namespace httpadapter {
struct BuyRequest {
  static application::BuyRequest ToType(const nlohmann::json& data);
};
}  // namespace httpadapter

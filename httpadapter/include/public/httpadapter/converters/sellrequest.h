#pragma once

#include <nlohmann/json.hpp>

#include "application/requests/sellrequest.h"

namespace httpadapter {
struct SellRequest {
  static application::SellRequest ToType(const nlohmann::json& data);
};
}  // namespace httpadapter

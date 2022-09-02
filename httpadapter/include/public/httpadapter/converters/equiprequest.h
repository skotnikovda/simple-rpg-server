#pragma once

#include <nlohmann/json.hpp>

#include "application/requests/equiprequest.h"

namespace httpadapter {
struct EquipRequest {
  static application::EquipRequest ToType(const nlohmann::json& data);
};
}  // namespace httpadapter

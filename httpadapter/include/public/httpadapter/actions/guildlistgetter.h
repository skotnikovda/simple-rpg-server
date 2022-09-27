#pragma once

#include "httpadapter/core/request.h"
#include "httpadapter/core/response.h"
#include "httpadapter/core/target.h"

namespace httpadapter {
struct GuildListGetter {
  static Target RequestTarget();
  static Response Get(const Request& request);
};
}  // namespace httpadapter

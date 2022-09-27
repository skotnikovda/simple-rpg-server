#pragma once

#include "httpadapter/core/request.h"
#include "httpadapter/core/response.h"
#include "httpadapter/core/target.h"

namespace httpadapter {
struct GuildJoiner {
  static Target RequestTarget();
  static Response Post(const Request& request);
};
}  // namespace httpadapter

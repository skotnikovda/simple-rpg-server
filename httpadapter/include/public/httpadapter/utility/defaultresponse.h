#pragma once

#include "httpadapter/core/response.h"

namespace httpadapter {
struct DefaultResponse {
  static Response MissingData();
  static Response ApplicationError();
};
}  // namespace httpadapter

#pragma once

#include <functional>

#include "request.h"
#include "response.h"

namespace httpadapter {
typedef std::function<Response(const Request&)> Handler;
}  // namespace httpadapter

#pragma once

#include <memory>

#include "httpadapter/boost/iocontext.h"
#include "httpadapter/boost/listener.h"

namespace httpadapter {
template <class Server>
concept ServerConcept = requires(Server server, IOContext io_context,
                                 std::shared_ptr<Listener> listener) {
  Server(io_context, listener);
};
}  // namespace httpadapter

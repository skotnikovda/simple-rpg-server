#pragma once

#include <map>
#include <typeindex>

#include "httpadapter/core/handler.h"

namespace httpadapter {
class RequestHandler {
 private:
  std::map<std::type_index, Handler> error_handlers_;
  Handler handler_;

 public:
  RequestHandler(const Handler&);
  template <class T>
  RequestHandler& handleError() {
    auto old_handler = handler_;
    auto new_handler = [=](const Request& request) {
      auto response = Response();
      try {
        response = old_handler(request);
      } catch (const T& e) {
        response = error_handlers_[typeid(T)](request);
      }
      return response;
    };
    handler_ = new_handler;
    return *this;
  }
  Response process(const Request&);
};
}  // namespace httpadapter

#pragma once

#include <concepts>
#include <functional>
#include <map>
#include <utility>

#include "handler.h"
#include "method.h"
#include "request.h"
#include "response.h"
#include "target.h"
#include "concepts/constructibleto.h"
#include "concepts/convertiblefrom.h"
#include "concepts/getresponding.h"
#include "concepts/postresponding.h"
#include "concepts/targeted.h"

namespace httpadapter {
class FrontController {
 private:
  std::map<std::string, Method> methods_;
  std::map<std::pair<Target, Method>, Handler> map_;
  Response default_response_;

 public:
  FrontController() {
    methods_["GET"] = Method::kGet;
    methods_["POST"] = Method::kPost;
    default_response_.set_code(ResponseStatus::kNotFound);
    default_response_.set_body("Not found");
  }

  template <Targeted Action>
  void RegisterAction() {
    auto target = Action::RequestTarget();
    if constexpr (GetResponding<Action>) {
      auto key = std::pair(target, Method::kGet);
      map_[key] = &Action::Get;
    }
    if constexpr (PostResponding<Action>) {
      auto key = std::pair(target, Method::kPost);
      map_[key] = &Action::Post;
    }
  }
  template <ConstructibleTo<Request> RawRequest,
            ConvertibleFrom<Response> RawResponse>
  RawResponse Handle(const RawRequest& raw_request) {
    auto request = Request(raw_request);
    auto target = request.target();
    auto method = request.method();
    std::cout << target << std::endl;
    auto key = std::pair(target, method);
    auto response = default_response_;
    if (map_.contains(key)) {
      auto handler = map_[key];
      response = handler(request);
    }
    return response;
  }
};
}  // namespace httpadapter

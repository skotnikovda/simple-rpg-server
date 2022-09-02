#pragma once

namespace httpadapter {
template <class Action>
concept PostResponding = requires(const Request& request) {
  { Action::Post(request) } -> std::same_as<Response>;
};
}  // namespace httpadapter

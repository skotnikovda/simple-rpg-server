#pragma once

namespace httpadapter {
template <class Action>
concept GetResponding = requires(const Request& request) {
  { Action::Get(request) } -> std::same_as<Response>;
};
}  // namespace httpadapter

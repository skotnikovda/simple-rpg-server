#pragma once

namespace httpadapter {
template <class Action>
concept Targeted = requires() {
  { Action::RequestTarget() } -> std::same_as<Target>;
};
}  // namespace httpadapter

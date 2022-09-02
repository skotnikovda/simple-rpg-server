#pragma once

namespace httpadapter {
template <class T1, class T2>
concept ConstructibleTo = std::constructible_from<T2, T1>;
}  // namespace httpadapter

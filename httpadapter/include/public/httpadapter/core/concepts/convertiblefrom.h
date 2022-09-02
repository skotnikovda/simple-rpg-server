#pragma once

namespace httpadapter {
template <class T1, class T2>
concept ConvertibleFrom = std::convertible_to<T2, T1>;
}  // namespace httpadapter

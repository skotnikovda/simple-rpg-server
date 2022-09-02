#pragma once

namespace application {
class ApplicationError : public std::runtime_error {
 public:
  using std::runtime_error::runtime_error;
};
}  // namespace application

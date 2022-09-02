#pragma once

#include "service.h"

namespace application {
class Registry {
 private:
  static std::shared_ptr<Service> service_;

 public:
  static void SetService(std::shared_ptr<Service>);
  static std::shared_ptr<Service> GetService();
};
}  // namespace application

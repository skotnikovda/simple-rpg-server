#include "application/registry.h"

namespace application {
std::shared_ptr<Service> Registry::service_ = nullptr;
void Registry::SetService(std::shared_ptr<Service> service) {
  service_ = service;
}
std::shared_ptr<Service> Registry::GetService() { return service_; }
}  // namespace application

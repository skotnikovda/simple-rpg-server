#include "domain/inventory.h"

#include <algorithm>

#include "domain/domainerror.h"

namespace domain {
Inventory::Inventory(const inventory::Size& size,
                     const std::vector<Item>& items)
    : size_(size), items_(items) {}
inventory::Size Inventory::size() const { return size_; }
const std::vector<Item>& Inventory::items() const { return items_; }
const Item& Inventory::item(const inventory::ItemIndex& index) const {
  if (index.value() >= items_.size()) {
    throw DomainError("Invalid item index");
  }
  return items_[index.value()];
}
inventory::ItemCount Inventory::count() const { return items_.size(); }
void Inventory::Insert(const Item& item) {
  if (items_.size() >= size_.value()) throw DomainError("Inventory is full");
  items_.push_back(item);
}
void Inventory::Extract(const inventory::ItemIndex& index) {
  if (index.value() >= items_.size())
    throw DomainError("Item index is out of range");
  items_.erase(items_.begin() + index.value());
}
}  // namespace domain

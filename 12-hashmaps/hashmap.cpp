#include <cstddef>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>

class HashMap {
 public:
  explicit HashMap(std::size_t size) : hashmap(size) {};

  std::size_t convertKeyToIndex(std::string_view key) const {
    if (hashmap.empty()) return 0;  // Guard against division by zero

    std::size_t total{0};
    for (char c : key) {
      total += static_cast<unsigned char>(c);
    }
    return total % hashmap.size();
  }

  void insert(std::string_view key, int value) {
    if (hashmap.empty()) {
      throw std::runtime_error("hashmap size is 0");
    }

    std::size_t index = convertKeyToIndex(key);
    std::size_t start_index = index;

    // Iterate as long as the current bucket is filled
    while (hashmap[index].has_value()) {
      auto& [stored_key, stored_value] = *hashmap[index];

      // Overwrite value if the key already exists
      if (stored_key == key) {
        stored_value = value;
        return;
      }

      index = (index + 1) % hashmap.size();

      if (index == start_index) {
        throw std::runtime_error("hashmap is full");
      }
    }

    // Found an empty bucket, insert the new tuple
    hashmap[index] = std::make_tuple(std::string(key), value);
  }

  std::tuple<std::string, int> get(std::string_view key) const {
    if (hashmap.empty()) {
      throw std::runtime_error("hashmap is empty");
    }

    std::size_t index = convertKeyToIndex(key);
    std::size_t start_index = index;

    while (hashmap[index].has_value()) {
      auto& [stored_key, stored_value] = *hashmap[index];

      if (stored_key == key) {
        return *hashmap[index];
      }

      index = (index + 1) % hashmap.size();

      if (index == start_index) {
        break;
      }
    }

    throw std::runtime_error("key not found");
  }

  float getCurrentLoad() const {
    if (hashmap.empty()) {
      return 1.0f;
    }

    float filled_buckets{0};
    // Use std::size_t to avoid signed/unsigned comparison warnings
    for (std::size_t i{0}; i < hashmap.size(); ++i) {
      if (hashmap[i].has_value()) {
        ++filled_buckets;
      }
    }
    return filled_buckets / hashmap.size();
  }

  void resize() {
    if (hashmap.empty()) {
      hashmap.resize(10);  // Give it a sensible non-zero default size
      return;
    }

    float current_load = getCurrentLoad();

    // Check if we ACTUALLY need to resize (e.g., more than 70% full)
    if (current_load < 0.70f) {
      return;
    }

    // Move the old map out, leaving the current hashmap empty
    auto old_hashmap = std::move(hashmap);

    std::size_t new_size = old_hashmap.size() * 10;
    // Resize the current map and fill it with empty optionals (std::nullopt)
    hashmap.assign(new_size, std::nullopt);

    // Re-insert old elements into the newly sized map
    for (auto& item : old_hashmap) {
      if (item.has_value()) {
        auto& [key, value] = *item;
        insert(key, value);  // This properly handles new collisions!
      }
    }
  }

 private:
  // Wrapped the tuple in std::optional to properly represent empty/filled
  // states
  std::vector<std::optional<std::tuple<std::string, int>>> hashmap;
};

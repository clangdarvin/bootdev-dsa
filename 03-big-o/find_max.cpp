#include <array>
#include <cstddef>
#include <iostream>
#include <optional>

namespace {

template <std::size_t N>
std::optional<int> findMax(const std::array<int, N>& arr) {
  // O(n) - Linear Runtime
  if (arr.empty()) {
    return std::nullopt;
  }
  int maximum{arr[0]};
  for (std::size_t i{1}; i < arr.size(); ++i) {
    if (arr[i] > maximum) {
      maximum = arr[i];
    }
  }
  return maximum;
}

}  // namespace

auto main() -> int {
  std::array<int, 4> arr{10, 5, 3, 11};
  std::optional<int> maximum{findMax(arr)};

  for (size_t i{0}; i < arr.size(); ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';

  if (!maximum) {
    std::cout << "Invalid.\n";
  } else {
    std::cout << "maximum: " << *maximum << '\n';
  }

  return 0;
}

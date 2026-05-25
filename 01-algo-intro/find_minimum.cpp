#include <array>
#include <cstddef>
#include <iostream>
#include <optional>

namespace {

template <std::size_t N>
std::optional<int> findMinimum(const std::array<int, N>& arr) {
  if (arr.empty()) {
    return std::nullopt;
  }
  int minimum{arr[0]};
  for (std::size_t i{1}; i < arr.size(); ++i) {
    if (arr[i] < minimum) {
      minimum = arr[i];
    }
  }
  return minimum;
}

}  // namespace

auto main() -> int {
  std::array<int, 4> arr{10, 5, 3, 11};
  std::optional<int> minimum{findMinimum(arr)};

  for (size_t i{0}; i < arr.size(); ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';

  if (!minimum) {
    std::cout << "Invalid.\n";
  } else {
    std::cout << "minimum: " << *minimum << '\n';
  }

  return 0;
}

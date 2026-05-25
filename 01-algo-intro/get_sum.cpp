#include <array>
#include <cstddef>
#include <iostream>

namespace {

template <std::size_t N>
int getSum(const std::array<int, N>& arr) {
  int sum{};
  if (arr.empty()) {
    sum = 0;
  }
  for (std::size_t i{0}; i < arr.size(); ++i) {
    sum += arr[i];
  }
  return sum;
}

}  // namespace

auto main() -> int {
  std::array<int, 4> arr{10, 5, 3, 11};

  for (size_t i{0}; i < arr.size(); ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';

  int sum{getSum(arr)};
  std::cout << "sum: " << sum << '\n';

  return 0;
}

#include <array>
#include <cstddef>
#include <iostream>

namespace {

template <std::size_t N>
int getAverageFollowers(const std::array<int, N>& arr) {
  int sum{};
  if (arr.empty()) {
    return 0;
  }
  for (std::size_t i{0}; i < arr.size(); ++i) {
    sum += arr[i];
  }
  return sum / arr.size();
}
}  // namespace

auto main() -> int {
  std::array<int, 5> arr{5, 10, 200, 3000, 5000};

  for (int val : arr) {
    std::cout << val << ' ';
  }
  std::cout << '\n';

  int average_followers{getAverageFollowers(arr)};
  std::cout << "average followers: " << average_followers << '\n';

  return 0;
}

// Median is more robust than Mean because it's not affected by outliers

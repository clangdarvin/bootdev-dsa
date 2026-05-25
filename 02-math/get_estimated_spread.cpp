#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>

namespace {

template <std::size_t N>
int getAudienceSpread(const std::array<int, N>& arr) {
  // Exponents
  if (arr.empty()) {
    return 0;
  }

  int sum{};

  for (int value : arr) {
    sum += value;
  }

  double average_audience_followers{static_cast<double>(sum) / arr.size()};

  return static_cast<int>(
      std::round(average_audience_followers * std::pow(arr.size(), 1.2)));
}

}  // namespace

auto main() -> int {
  std::array<int, 5> arr{50, 60, 70, 80, 90};

  for (size_t i{0}; i < arr.size(); ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';

  int estimated_spread{getAudienceSpread(arr)};
  std::cout << "estimated spread: " << estimated_spread << '\n';

  return 0;
}

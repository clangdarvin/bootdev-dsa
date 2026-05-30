#include <array>
#include <cmath>
#include <iostream>
#include <ranges>

namespace views = std::views;

namespace {

template <std::size_t N>
auto getLogScale(const std::array<int, N>& arr, double base) {
  return arr | views::all | views::transform([base](int x) {
           return std::log(x) / std::log(base);
         });
}

}  // namespace

auto main() -> int {
  std::array<int, 4> arr{3, 9, 27, 81};

  auto result{getLogScale(arr, 3)};

  for (int value : arr) {
    std::cout << value << ' ';
  }

  std::cout << '\n';

  for (double value : result) {
    std::cout << value << ' ';
  }

  std::cout << '\n';

  return 0;
}

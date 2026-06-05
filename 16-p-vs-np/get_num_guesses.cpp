#include <cmath>
#include <iostream>
namespace {
int getNumGuesses(int length) {
  int total{0};
  for (int i{0}; i < length + 1; ++i) {
    total += std::pow(26, i);
  }
  return total;
}
}  // namespace

auto main() -> int {
  std::cout << getNumGuesses(3) << '\n';
  return 0;
}

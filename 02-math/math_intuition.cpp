#include <cmath>
#include <iostream>
#include <vector>

namespace {

double exponentiation(int n) { return std::pow(n, 2); }

double logarithmic(int n) { return std::log2(n); }

unsigned long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  return n * factorial(n - 1);
}

}  // namespace

auto main() -> int {
  std::vector<int> test_sizes{1, 2, 5, 10, 15, 20};

  for (int n : test_sizes) {
    std::cout << "n = " << n << '\n';
    std::cout << "  exponentiation: " << exponentiation(n) << '\n';
    std::cout << "  logarithmic: " << logarithmic(n) << '\n';
    std::cout << "  factorial: " << factorial(n) << '\n';
    std::cout << '\n';
  }

  return 0;
}

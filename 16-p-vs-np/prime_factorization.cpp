#include <cmath>
#include <iostream>
#include <vector>
namespace {
std::vector<int> primeFactors(int n) {
  std::vector<int> factors{};
  while (n % 2 == 0) {
    factors.push_back(n);
    n /= 2;
  }
  int i{3};
  while (i <= std::sqrt(n)) {
    while (n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
    i += 2;
  }
  if (n > 1) {
    factors.push_back(n);
  }
  return factors;
}
}  // namespace
auto main() -> int {
  int n{49};
  std::vector<int> factors{primeFactors(n)};
  for (const int factor : factors) {
    std::cout << factor << ' ';
  }
  std::cout << '\n';
  return 0;
}

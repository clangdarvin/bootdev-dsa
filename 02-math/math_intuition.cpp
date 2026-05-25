#include <cmath>
#include <iostream>
namespace {
double exponentiation(int n) { return std::pow(n, 2); }
double logarithmic(int n) { return log2(n); }
int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return n * factorial(n - 1);
}
}  // namespace

auto main() -> int {
  int n{5};
  std::cout << "exponentiation: " << exponentiation(n) << '\n';
  std::cout << "logarithmic: " << logarithmic(n) << '\n';
  std::cout << "factorial: " << factorial(n) << '\n';
  return 0;
}

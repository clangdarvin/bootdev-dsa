#include <iostream>
namespace {
int fibonacciRecursive(int n) {
  // Exponential Runtime
  if (n <= 1) {
    return n;
  }
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciP(int n) {
  if (n <= 1) {
    return n;
  }
  int grandparent{0};
  int parent{1};
  int current{};
  for (int i{0}; i < n - 1; i++) {
    current = parent + grandparent;
    grandparent = parent;
    parent = current;
  }
  return parent;
}
}  // namespace

auto main() -> int {
  int n{70};
  // std::cout << fibonacciRecursive(n) << '\n';
  // the recursive approach is slow to run when n is large
  std::cout << fibonacciP(n) << '\n';
  return 0;
}

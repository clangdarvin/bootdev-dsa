#include <iostream>
namespace {
int getNumberOfPossibleOrders(int num_posts) {
  // Factorial
  if (num_posts == 0 || num_posts == 1) {
    return 1;
  }
  return num_posts * getNumberOfPossibleOrders(num_posts - 1);
}
}  // namespace

auto main() -> int {
  int num_posts{6};
  std::cout << getNumberOfPossibleOrders(num_posts) << '\n';
  return 0;
}

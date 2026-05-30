#include <iostream>
namespace {
int naiveLog2(int x) {
  int count{0};
  while (x > 1) {
    x /= 2;
    count += 1;
  }
  return count;
}
}  // namespace

auto main() -> int {
  int x{8};
  std::cout << naiveLog2(x) << '\n';
  return 0;
}

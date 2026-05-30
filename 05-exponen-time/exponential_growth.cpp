#include <iostream>
#include <vector>
namespace {
std::vector<int> exponentialGrowth(int n, int factor, int days) {
  std::vector<int> daily_followers = {n};
  for (int i{0}; i < days; ++i) {
    n = n * factor;
    daily_followers.push_back(n);
  }
  return daily_followers;
}
}  // namespace

auto main() -> int {
  int initial_followers{10};
  int growth_factor{2};
  int days{4};
  std::vector<int> growth_sequence{
      exponentialGrowth(initial_followers, growth_factor, days)};

  for (int g : growth_sequence) {
    std::cout << g << ' ';
  }
  std::cout << '\n';
  return 0;
}

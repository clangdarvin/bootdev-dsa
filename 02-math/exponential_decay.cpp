#include <cmath>
#include <iostream>
namespace {
int getDecayedFollowers(int initial_followers, double fraction_lost_daily,
                        int days) {
  double retention_rate{1 - fraction_lost_daily};
  return initial_followers * (std::pow(retention_rate, days));
}
}  // namespace

auto main() -> int {
  int initial_followers{1000};
  double fraction_lost_daily{0.05};
  int days{3};
  std::cout << getDecayedFollowers(initial_followers, fraction_lost_daily, days)
            << '\n';
  return 0;
}

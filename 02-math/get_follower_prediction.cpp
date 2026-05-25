#include <cmath>
#include <iostream>
#include <string_view>
namespace {
int getFollowerPrediction(int follower_count, std::string_view influencer_type,
                          int num_months) {
  // Exponents
  if (influencer_type == "cosmetic") {
    return static_cast<int>(follower_count * (std::pow(3, num_months)));
  }
  if (influencer_type == "fitness") {
    return static_cast<int>(follower_count * (std::pow(4, num_months)));
  }
  return static_cast<int>(follower_count * (std::pow(2, num_months)));
}
}  // namespace

auto main() -> int {
  int follower_count{10};
  std::string_view influencer_type{"fitness"};
  int num_months{5};

  std::cout << "expected followers: "
            << getFollowerPrediction(follower_count, influencer_type,
                                     num_months)
            << '\n';
  return 0;
}

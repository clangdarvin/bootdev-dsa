#include <cmath>
#include <iostream>
namespace {
int getInfluencerScore(int num_followers,
                       double average_engagement_percentage) {
  return static_cast<int>(
      std::round(average_engagement_percentage * std::log2(num_followers)));
}
}  // namespace

auto main() -> int {
  int num_followers{40000};
  double average_engagement_percentage{0.3};
  std::cout << "influencer score: "
            << getInfluencerScore(num_followers, average_engagement_percentage)
            << '\n';
  return 0;
}

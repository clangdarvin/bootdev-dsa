#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
namespace {
int countMarketers(const std::vector<std::string_view>& job_titles) {
  int count{0};

  for (std::string_view title : job_titles) {
    std::string lower{title};

    std::transform(lower.begin(), lower.end(), lower.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    if (lower == "marketer") {
      ++count;
    }
  }

  return count;
}
}  // namespace

auto main() -> int {
  std::vector<std::string_view> job_titles{"developer", "marketer", "designer",
                                           "MARKETER", "Marketer"};
  int count{countMarketers(job_titles)};

  std::cout << "Count: " << count << '\n';
  return 0;
}

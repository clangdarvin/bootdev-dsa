#include <iostream>
#include <string_view>
#include <vector>
namespace {

double getAverageBrandFollowers(
    const std::vector<std::vector<std::string_view>>& all_handles,
    std::string_view brand_name) {
  // O(nm)
  double occurrence{0};

  for (std::size_t i{0}; i < all_handles.size(); ++i) {
    for (size_t j{0}; j < all_handles[i].size(); ++j) {
      if (all_handles[i][j].find(brand_name) != std::string_view::npos) {
        ++occurrence;
      }
    }
  }
  return occurrence / all_handles.size();
}
}  // namespace

auto main() -> int {
  std::vector<std::vector<std::string_view>> all_handles = {
      {"cosmofan1010", "cosmogirl", "billjane321"},
      {"cosmokiller", "gr8", "cosmojane3"},
      {"iloveboots", "paperthin"}};
  std::string_view brand_name{"cosmo"};

  std::cout << "average brand followers: "
            << getAverageBrandFollowers(all_handles, brand_name) << '\n';
  return 0;
}

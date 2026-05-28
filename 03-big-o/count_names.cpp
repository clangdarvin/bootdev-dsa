#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string_view>
#include <vector>
namespace {
int countNames(std::vector<std::vector<std::string_view>>& list_of_lists,
               std::string_view target_name) {
  // O(n)
  int freq{0};
  for (size_t i{0}; i < list_of_lists.size(); ++i) {
    freq += std::count(list_of_lists[i].begin(), list_of_lists[i].end(),
                       target_name);
  }
  return freq;
}
}  // namespace

auto main() -> int {
  std::vector<std::vector<std::string_view>> list_of_lists{
      {"George", "Eva", "George"}, {"Diane", "George", "Eva", "Frank"}};
  std::string_view target_name{"George"};
  int freq{countNames(list_of_lists, target_name)};
  std::cout << "Frequency of " << target_name << ": " << freq << '\n';
  return 0;
}

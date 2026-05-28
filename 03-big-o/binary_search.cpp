#include <cstddef>
#include <ios>
#include <iostream>
#include <vector>
namespace {
bool binarySearch(int target, std::vector<int>& nums) {
  // O(log(n)) - Logarithmic
  std::size_t low{0};
  std::size_t high{nums.size() - 1};
  while (low <= high) {
    size_t mid{(low + high) / 2};
    if (nums[mid] == target) {
      return true;
    }
    if (nums[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
}  // namespace

auto main() -> int {
  std::vector<int> nums{3, 5, 7, 8, 9, 10, 12, 15, 20};
  int target{6};

  for (int num : nums) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  std::cout << "Does " << target << " exists? " << std::boolalpha
            << binarySearch(target, nums) << '\n';

  return 0;
}

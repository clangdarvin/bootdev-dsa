#include <algorithm>
#include <iostream>
#include <vector>
namespace {

bool findSubsetSum(std::vector<int>& nums, int target, int index) {
  if (target == 0) {
    return true;
  }

  if (index < 0 && target != 0) {
    return false;
  }

  if (nums[index] > target) {
    return findSubsetSum(nums, target, index - 1);
  }

  bool exclude{findSubsetSum(nums, target, index - 1)};
  bool include{findSubsetSum(nums, target - nums[index], index - 1)};

  return exclude || include;
}

bool subsetSum(std::vector<int>& nums, int target) {
  return findSubsetSum(nums, target, nums.size() - 1);
}

}  // namespace

auto main() -> int {
  std::vector<int> nums{3, 34, 4, 12, 5, 2};

  std::cout << std::boolalpha;
  std::cout << subsetSum(nums, 9) << '\n';   // true (4 + 5)
  std::cout << subsetSum(nums, 30) << '\n';  // false
  return 0;
}

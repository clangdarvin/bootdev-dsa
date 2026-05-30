#include <cstddef>
#include <iostream>
#include <vector>
namespace {
void selectionSort(std::vector<int>& nums) {
  for (int i{0}; i < nums.size(); i++) {
    int idx{i};
    for (int j{i + 1}; j < nums.size(); j++) {
      if (nums[j] < nums[idx]) {
        idx = j;
      }
    }
    int temp{nums[i]};
    nums[i] = nums[idx];
    nums[idx] = temp;
  }
}

}  // namespace

auto main() -> int {
  std::vector<int> nums{5, 3, 8, 6, 1, 9};

  selectionSort(nums);
  for (int num : nums) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}

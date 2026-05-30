#include <cstddef>
#include <iostream>
#include <vector>
namespace {
std::vector<int> bubbleSort(std::vector<int>& nums) {
  /**
   * O(n^2) - Quadratic
   * Best Case (already sorted): O(n)
   * Worst Case (reverse order): O(n^2)
   *
   * Pseudocode
   *    swapped <- true
   *    while swapped:
   *        swapped <- false
   *        for i <- 1 to n - 1:
   *            if arr[i-1] > arr[i]
   *                swap arr[i-1] & arr[i]
   *                swapped <- true
   */
  bool swap{true};
  while (swap) {
    swap = false;
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i - 1] > nums[i]) {
        int temp{nums[i - 1]};
        nums[i - 1] = nums[i];
        nums[i] = temp;
        swap = true;
      }
    }
  }
  return nums;
}
}  // namespace

auto main() -> int {
  std::vector<int> nums{10, 3, 5, 8, 5, 2, 0};
  std::vector<int> sorted_nums{bubbleSort(nums)};

  std::cout << "sorted nums" << '\n';
  for (int num : sorted_nums) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}

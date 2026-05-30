#include <cstddef>
#include <iostream>
#include <vector>
namespace {
std::vector<int> insertionSort(std::vector<int>& nums) {
  // O(n^2) - Quadratic
  //
  // Best Case (already sorted): O(n)
  // Worst Case (reverse order): O(n^2)
  //
  // Fast for small data
  //
  // Pseudocode
  //    for i <- 1 to n
  //        j <- i
  //        while j > 0 and A[j-1] > A[j]
  //            swap A[j] and A[j-1]
  //            j -= 1
  //
  // [5, 4, 3, 2, 1]
  // [4, 5, 3, 2, 1]
  // [3, 4, 5, 2, 1]
  // [2, 3, 4, 5, 1]
  // [1, 2, 3, 4, 5]

  for (std::size_t i{1}; i < nums.size(); ++i) {
    std::size_t j{i};
    while ((j > 0) && (nums[j - 1] > nums[j])) {
      int temp{nums[j]};
      nums[j] = nums[j - 1];
      nums[j - 1] = temp;
      --j;
    }
  }
  return nums;
}
}  // namespace

auto main() -> int {
  std::vector<int> nums{5, 4, 3, 2, 1};
  std::vector<int> sorted_nums{insertionSort(nums)};

  for (int num : sorted_nums) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}

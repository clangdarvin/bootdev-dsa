#include <iostream>
#include <vector>
namespace {

int createPartition(std::vector<int>& nums, int low, int high) {
  // Pseudocode
  //    pivot <- element at high
  //    i <- low - 1
  //    for j <- low to high:
  //        if A[j] < pivot
  //            i <- i + 1
  //            swap A[i], A[j]
  //    swap A[i+1], high
  //    return i+1
  //
  int pivot{nums[high]};
  int i{low - 1};

  for (int j{low}; j < high; ++j) {
    if (nums[j] < pivot) {
      ++i;

      int temp{nums[i]};
      nums[i] = nums[j];
      nums[j] = temp;
    }
  }

  int temp{nums[i + 1]};
  nums[i + 1] = nums[high];
  nums[high] = temp;

  return i + 1;
}

void quickSort(std::vector<int>& nums, int low, int high) {
  // O(n log(n)) - Linearithmic
  // Best Case: O(n log(n))
  // Worst Case (already sorted): O(n^2)
  //
  // The algorithm can be fixed by following a median approach
  //    pivot = median(low, mid, high)
  //
  // compare j, pivot: swap i, j
  // swap i+1, high
  //
  // Pseudocode
  // if low < high
  //    mid <- createPartition
  //    quickSort(A, low, mid - 1)
  //    quickSort(A, mid + 1, high)
  //
  if (low < high) {
    int mid{createPartition(nums, low, high)};
    quickSort(nums, low, mid - 1);
    quickSort(nums, mid + 1, high);
  }
}

}  // namespace

auto main() -> int {
  std::vector<int> nums{9, 6, 2, 1, 8, 7};
  quickSort(nums, 0, nums.size() - 1);
  for (int num : nums) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}

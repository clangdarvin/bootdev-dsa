#include <iostream>
#include <vector>

namespace {

std::vector<int> merge(std::vector<int>& left, std::vector<int>& right) {
  /**
   * Pseudocode
   *    sorted_arr <- []
   *    i <- 0, j <- 0
   *    while i < size(L) and j < size(R):
   *        if L[i] < R[j]
   *            sorted_arr.push(L[i])
   *            i += 1
   *        else
   *            sorted_arr.push(R[j])
   *            j += 1
   *    sorted_arr.insert(L[i:])
   *    sorted_arr.insert(R[j:])
   *
   *    [6, 5, 4, 3, 2, 1]
   *    [6, 5, 4]            [3, 2, 1]
   *    [6, 5]   [4]         [3, 2]   [1]
   *    [6] [5]  [4]         [3] [2]  [1]
   *    [5, 6]   [4]         [2, 3]   [1]
   *    [4, 5, 6]            [1, 2, 3]
   *    [1, 2, 3, 4, 5, 6]
   **/
  std::vector<int> sorted_arr{};

  std::size_t i{0};
  std::size_t j{0};

  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      sorted_arr.push_back(left[i]);
      ++i;
    } else {
      sorted_arr.push_back(right[j]);
      ++j;
    }
  }

  sorted_arr.insert(sorted_arr.end(), left.begin() + static_cast<long>(i),
                    left.end());

  sorted_arr.insert(sorted_arr.end(), right.begin() + static_cast<long>(j),
                    right.end());

  return sorted_arr;
}

std::vector<int> mergeSort(std::vector<int>& nums) {
  // O(n log(n)) - Linearithmic
  // Divide and Conquer: from large problem to smaller problem, recursively
  // solve Use if memory isn't an issue

  /**
   * Pseudocode
   *    if size(A) <= 1:
   *        return arr
   *    mid <- size(A) / 2
   *    left <- A[0:mid]
   *    right <- A[mid:size(A)]
   *    sort_left <- merge_sort(left)
   *    sort_right <- merge_sort(right)
   *    return merge(sort_left, sort_right)
   }
   * */
  if (nums.size() <= 1) {
    return nums;
  }

  std::size_t mid{nums.size() / 2};

  std::vector<int> left(nums.begin(), nums.begin() + mid);
  std::vector<int> right(nums.begin() + mid, nums.end());

  std::vector<int> sorted_left{mergeSort(left)};
  std::vector<int> sorted_right{mergeSort(right)};

  return merge(sorted_left, sorted_right);
}

}  // namespace

auto main() -> int {
  std::vector<int> nums{4, -7, 1, 0, 5};

  std::vector<int> sorted_arr{mergeSort(nums)};

  for (int num : sorted_arr) {
    std::cout << num << ' ';
  }

  std::cout << '\n';

  return 0;
}

#include <iostream>
#include <vector>
namespace {

std::vector<std::vector<int>> helper(std::vector<std::vector<int>> res,
                                     std::vector<int> arr, int n) {
  if (n == 1) {
    std::vector<int> temp{arr};
    res.push_back(temp);
  } else {
    for (int i{0}; i < n; ++i) {
      res = helper(res, arr, n - 1);
      if (n % 2 == 1) {
        int temp = arr[n - 1];
        arr[n - 1] = arr[i];
        arr[i] = temp;
      } else {
        int temp = arr[n - 1];
        arr[n - 1] = arr[0];
        arr[0] = temp;
      }
    }
  }
  return res;
}
std::vector<std::vector<int>> permutations(const std::vector<int>& arr) {
  std::vector<std::vector<int>> res{};
  res = helper(res, arr, arr.size());
  return res;
}
bool tsp(const std::vector<int>& cities,
         const std::vector<std::vector<int>>& paths, int distance) {
  std::vector<std::vector<int>> possible_paths{permutations(cities)};

  for (const auto& possible_path : possible_paths) {
    int total_distance{0};

    for (size_t i{0}; i < possible_path.size() - 1; ++i) {
      int current_city = possible_path[i];
      int next_city = possible_path[i + 1];

      total_distance += paths[current_city][next_city];
    }

    if (total_distance < distance) {
      return true;
    }
  }

  return false;
}
}  // namespace

auto main() -> int {
  std::vector<int> cities{0, 1, 2};

  std::vector<std::vector<int>> paths{
      {0, 10, 15},
      {10, 0, 20},
      {15, 20, 0},
  };

  int distance{35};

  if (tsp(cities, paths, distance)) {
    std::cout << "True\n";
  } else {
    std::cout << "False\n";
  }

  auto perms = permutations(cities);

  for (const auto& p : perms) {
    for (int city : p) {
      std::cout << city << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

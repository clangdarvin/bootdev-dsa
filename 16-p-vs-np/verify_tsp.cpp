#include <iostream>
#include <vector>

bool verifyTSP(const std::vector<std::vector<int>>& paths, int distance,
               const std::vector<int>& actual_path) {
  int total_distance{0};

  if (actual_path.size() < 2) {
    return true;
  }

  for (size_t i{0}; i < actual_path.size() - 1; ++i) {
    int current_city{actual_path[i]};
    int next_city{actual_path[i + 1]};

    total_distance += paths[current_city][next_city];
  }

  return total_distance < distance;
}

auto main() -> int {
  std::vector<std::vector<int>> paths{
      {0, 10, 15},
      {10, 0, 20},
      {15, 20, 0},
  };

  std::vector<int> actual_path{0, 1, 2};

  int distance{35};

  if (verifyTSP(paths, distance, actual_path)) {
    std::cout << "True\n";
  } else {
    std::cout << "False\n";
  }

  return 0;
}

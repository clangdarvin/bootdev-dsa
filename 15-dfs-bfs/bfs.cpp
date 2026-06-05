#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Graph {
  // Use BFS if you know the solution is close to the root
 public:
  void add_edge(const std::string& u, const std::string& v) {
    graph[u].insert(v);
    graph[v].insert(u);
  }

  std::vector<std::string> breadth_first_search(const std::string& start) {
    std::vector<std::string> visited;
    std::queue<std::string> explore;

    explore.push(start);

    while (!explore.empty()) {
      std::string current = explore.front();
      explore.pop();

      if (std::find(visited.begin(), visited.end(), current) != visited.end()) {
        continue;
      }

      visited.push_back(current);

      // collect and sort neighbors
      std::vector<std::string> neighbors(graph[current].begin(),
                                         graph[current].end());
      std::sort(neighbors.begin(), neighbors.end());

      for (const auto& n : neighbors) {
        bool in_visited =
            std::find(visited.begin(), visited.end(), n) != visited.end();

        bool in_queue = false;
        std::queue<std::string> temp = explore;
        while (!temp.empty()) {
          if (temp.front() == n) {
            in_queue = true;
            break;
          }
          temp.pop();
        }

        if (!in_visited && !in_queue) {
          explore.push(n);
        }
      }
    }

    return visited;
  }

  // debugging helper
  void print() const {
    for (const auto& [key, neighbors] : graph) {
      std::cout << "Vertex: '" << key << "'\n";
      std::vector<std::string> sorted_neighbors(neighbors.begin(),
                                                neighbors.end());
      std::sort(sorted_neighbors.begin(), sorted_neighbors.end());

      for (const auto& v : sorted_neighbors) {
        std::cout << "has an edge leading to --> " << v << "\n";
      }
    }
  }

 private:
  std::unordered_map<std::string, std::unordered_set<std::string>> graph;
};

int main() {
  Graph g;

  g.add_edge("A", "B");
  g.add_edge("A", "C");
  g.add_edge("B", "D");
  g.add_edge("C", "D");

  auto result = g.breadth_first_search("A");

  for (const auto& v : result) {
    std::cout << v << " ";
  }
  std::cout << "\n";

  return 0;
}

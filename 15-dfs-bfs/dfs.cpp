
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Graph {
  // Use DFS if the tree has wide levels
 public:
  void add_edge(const std::string& u, const std::string& v) {
    graph[u].insert(v);
    graph[v].insert(u);
  }

  std::vector<std::string> depth_first_search(const std::string& start_vertex) {
    std::vector<std::string> visited;
    depth_first_search_recursive(visited, start_vertex);
    return visited;
  }

  void depth_first_search_recursive(std::vector<std::string>& visited,
                                    const std::string& current_vertex) {
    visited.push_back(current_vertex);

    for (const auto& neighbor : graph[current_vertex]) {
      if (std::find(visited.begin(), visited.end(), neighbor) ==
          visited.end()) {
        depth_first_search_recursive(visited, neighbor);
      }
    }
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

  auto result = g.depth_first_search("A");

  for (const auto& v : result) {
    std::cout << v << " ";
  }
  std::cout << "\n";

  return 0;
}

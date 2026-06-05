#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

class Graph {
  // undirected graph: n(n-1)/2 edges for n vertices
  // vertices: 4, edges: 6
 public:
  Graph(int n) : num_vertices(n), graph({}) {}

  void addEdge(int u, int v) {
    if (!graph.contains(u)) {
      graph[u] = {};
    }
    if (!graph.contains(v)) {
      graph[v] = {};
    }
    graph[u].insert(v);
    graph[v].insert(u);
  }

  std::set<int> adjacentNodes(int node) { return graph[node]; }
  std::vector<int> unconnectedVertices() {
    std::vector<int> unconnected{};
    for (int v{0}; v < num_vertices; ++v) {
      if (!graph.contains(v) || graph.at(v).empty()) {
        unconnected.push_back(v);
      }
    }
    return unconnected;
  }

 private:
  int num_vertices;
  std::unordered_map<int, std::set<int>> graph;
};
auto main() -> int {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);
  std::set<int> adjacent_nodes = {g.adjacentNodes(1)};
  std::cout << "Adjacent Nodes of Node 1" << '\n';
  for (const int node : adjacent_nodes) {
    std::cout << node << ' ';
  }
  std::cout << '\n';
  return 0;
}

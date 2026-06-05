#pragma once
#include <vector>
class Stack {
  // Last In, First Out (LIFO)
  // push, pop, peek, size: O(1)

 public:
  void push(int item) { items.push_back(item); }

  void pop() {
    if (!items.empty()) {
      items.pop_back();
    }
  }

  int peek() const {
    if (items.empty()) {
      return -1;  // sentinel value
    }
    return items.back();
  }

  bool isEmpty() { return items.empty(); }

  [[nodiscard]] int size() const { return static_cast<int>(items.size()); }

 private:
  std::vector<char> items;
};

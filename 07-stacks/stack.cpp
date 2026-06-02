#include <iostream>
#include <vector>

namespace {

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

  [[nodiscard]] int size() const { return static_cast<int>(items.size()); }

 private:
  std::vector<int> items;
};

}  // namespace

auto main() -> int {
  Stack stack{};

  std::cout << "Size: " << stack.size() << '\n';

  stack.push(300);
  stack.push(70);

  std::cout << "Size: " << stack.size() << '\n';
  std::cout << "Top: " << stack.peek() << '\n';

  stack.pop();

  std::cout << "Size: " << stack.size() << '\n';
  std::cout << "Top: " << stack.peek() << '\n';

  return 0;
}

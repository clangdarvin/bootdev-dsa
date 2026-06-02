#include <deque>
#include <iostream>
namespace {
class Queue {
  // First In, First Out
  // Add items to the tail, and remove from the head
  // Main operations: enqueue, dequeue, peek
  // Use queue if the ordering matters
 public:
  void enqueue(int item) { items.push_back(item); }

  int dequeue() {
    if (items.empty()) {
      return -1;
    }
    int removed = items.front();
    items.pop_front();
    return removed;
  }

  int peek() {
    if (items.empty()) {
      return -1;
    }
    return items.front();
  }

  int size() { return static_cast<int>(items.size()); }

 private:
  std::deque<int> items;
};
}  // namespace

auto main() -> int {
  Queue queue;
  queue.enqueue(10);
  queue.enqueue(50);
  queue.enqueue(30);

  std::cout << "Size: " << queue.size() << '\n';

  std::cout << "Peek: " << queue.peek() << '\n';
  queue.dequeue();

  std::cout << "Size: " << queue.size() << '\n';
  std::cout << "Peek: " << queue.peek() << '\n';
  return 0;
}

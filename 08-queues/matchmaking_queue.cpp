#include <deque>
#include <iostream>
#include <string_view>
namespace {
struct User {
  std::string_view name;
  std::string_view action;
};

class Queue {
 public:
  void enqueue(std::string_view name) { items.push_back(name); }
  std::string_view dequeue() {
    if (items.empty()) {
      return "Empty";
    }
    items.pop_front();
    return items.front();
  }

  std::string_view peek() {
    if (items.empty()) {
      return "Empty";
    }
    return items.front();
  }

  int size() {
    if (items.empty()) {
      return -1;
    }
    return static_cast<int>(items.size());
  }

 private:
  std::deque<std::string_view> items;
};
}  // namespace

auto main() -> int {
  Queue queue;
  queue.enqueue("Marshall");
  queue.enqueue("Barney");
  queue.enqueue("Ted");

  User user{.name = "Lily", .action = "join"};
  if (user.action == "leave") {
    std::string_view peek{queue.peek()};
    if (peek == user.name) {
      queue.dequeue();
    }
  }

  if (user.action == "join") {
    queue.enqueue(user.name);
  }

  if (queue.size() >= 4) {
    std::string_view user1{queue.dequeue()};
    std::string_view user2{queue.dequeue()};
    std::cout << user1 << " matched " << user2 << "!" << '\n';
  } else {
    std::cout << "No match found" << '\n';
  }
  return 0;
}

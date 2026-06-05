#include <iostream>

#include "node.h"

namespace {

class LinkedListQueue {
  // There are no indices
  // Ideal to use when insertion and deletion is in the middle of a list
 public:
  LinkedListQueue() : head(nullptr), tail(nullptr) {}

  Node* getHead() { return head; }

  void addTail(Node* node) {
    if (head == nullptr) {
      head = node;
      tail = node;
      return;
    }

    tail->setNext(node);
    tail = node;
  }

  void addHead(Node* node) {
    node->setNext(head);
    head = node;

    if (tail == nullptr) {
      tail = node;
    }
  }

  Node* removeHead() {
    if (head == nullptr) {
      return nullptr;
    }
    Node* remove_head{head};
    head = remove_head->getNext();
    if (head == nullptr) {
      tail = nullptr;
    }
    remove_head->setNext(nullptr);
    return remove_head;
  }

  void print() const {
    Node* node = head;

    while (node != nullptr) {
      std::cout << node->getVal() << " -> " << ' ';
      node = node->getNext();
    }

    std::cout << '\n';
  }

 private:
  Node* head;
  Node* tail;
};

}  // namespace

auto main() -> int {
  LinkedListQueue ll;

  Node n1{15};
  Node n2{94};
  ll.addHead(&n1);
  ll.addTail(&n2);
  ll.print();
  ll.removeHead();
  ll.print();

  return 0;
}

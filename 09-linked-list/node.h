class Node {
 public:
  explicit Node(int val) : val(val), next(nullptr) {}

  void setNext(Node* node) { next = node; }

  [[nodiscard]] int getVal() const { return val; }
  [[nodiscard]] Node* getNext() const { return next; }

 private:
  int val;
  Node* next;
};

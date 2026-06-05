#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
namespace {
class BSTNode {
  // Constraints
  // Each node has 2 children (binary)
  // Left child's value < Parent value
  // Right child's value > Parent value
  // 2 nodes must not have the same value
  // Searchable Property which Stacks and Queues don't have
  //
  // Not self-balancing
  //
  // Balanced BST: O(log n)
  // Unbalanced BST: O(n) if we insert already sorted input [10, 20, 30, 40, 50]
  // Operations: insert, delete, getmin, getmax, traversals: {preorder, inorder,
  // postorder}, exists, height
 public:
  explicit BSTNode(int val) : val(val), left(nullptr), right(nullptr) {}

  void insert(int value) {
    if (val == value) {
      return;
    }

    if (value < val) {
      if (left == nullptr) {
        left = new BSTNode(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BSTNode(value);
      } else {
        right->insert(value);
      }
    }
  }

  int getMin() const {
    const BSTNode* current = this;

    while (current->left != nullptr) {
      current = current->left;
    }

    return current->val;
  }

  int getMax() const {
    const BSTNode* current = this;

    while (current->right != nullptr) {
      current = current->right;
    }

    return current->val;
  }

  int getHeight() {
    int left_height{-1};
    int right_height{-1};
    if (left != nullptr) {
      left_height = left->getHeight();
    }
    if (right != nullptr) {
      right_height = right->getHeight();
    }
    return std::max(left_height, right_height) + 1;
  }

  BSTNode* deleteNode(int value) {
    if (value < val) {
      if (left != nullptr) {
        left = left->deleteNode(value);
      }
      return this;
    }

    if (value > val) {
      if (right != nullptr) {
        right = right->deleteNode(value);
      }
      return this;
    }

    if (right == nullptr) {
      return left;
    }

    if (left == nullptr) {
      return right;
    }

    // Find the in-order successor (smallest value in right subtree)
    BSTNode* successor = right;
    while (successor->left != nullptr) {
      successor = successor->left;
    }

    val = successor->val;
    right = right->deleteNode(successor->val);

    return this;
  }

  std::vector<int> preorder(std::vector<int>& visited) {
    // Root -> Left -> Right
    visited.push_back(val);
    if (left != nullptr) {
      left->preorder(visited);
    }
    if (right != nullptr) {
      right->preorder(visited);
    }
    return visited;
  }

  std::vector<int> postorder(std::vector<int>& visited) {
    // Left -> Right -> Root
    if (left != nullptr) {
      left->postorder(visited);
    }
    if (right != nullptr) {
      right->postorder(visited);
    }
    visited.push_back(val);
    return visited;
  }

  std::vector<int> inorder(std::vector<int>& visited) {
    // Left -> Root -> Right
    if (left != nullptr) {
      left->inorder(visited);
    }

    visited.push_back(val);

    if (right != nullptr) {
      right->inorder(visited);
    }

    return visited;
  }

  bool exists(int value) {
    if (val == value) {
      return true;
    }

    if (value < val) {
      return (left != nullptr && left->exists(value));
    }

    if (value > val) {
      return (right != nullptr && right->exists(value));
    }

    return false;
  }

  ~BSTNode() {
    delete left;
    delete right;
  }

 private:
  int val;
  BSTNode* left;
  BSTNode* right;
};
}  // namespace

auto main() -> int {
  BSTNode root{10};
  // root.insert(15);
  // root.insert(30);
  // root.insert(11);
  root.insert(20);
  root.insert(30);
  root.insert(40);
  root.insert(50);

  std::cout << "Min: " << root.getMin() << '\n';
  std::cout << "Max: " << root.getMax() << '\n';

  std::vector<int> preorder_result;
  root.preorder(preorder_result);
  std::cout << "Preorder: ";
  for (int res : preorder_result) {
    std::cout << res << ' ';
  }
  std::cout << '\n';

  std::vector<int> postorder_result;
  root.postorder(postorder_result);
  std::cout << "Postorder: ";
  for (int res : postorder_result) {
    std::cout << res << ' ';
  }
  std::cout << '\n';

  std::vector<int> inorder_result;
  root.inorder(inorder_result);
  std::cout << "Inorder: ";
  for (int res : inorder_result) {
    std::cout << res << ' ';
  }
  std::cout << '\n';

  int target{11};
  std::cout << "Does " << target << " exists? " << std::boolalpha
            << root.exists(target) << '\n';
  std::cout << "Height of the tree: " << root.getHeight() << '\n';
  return 0;
}

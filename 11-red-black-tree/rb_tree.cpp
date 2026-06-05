#include <iostream>
#include <vector>

#include "node.h"
class RBTree {
  // O(log (n))
  // Root: Black
  // NIL Leaf Nodes: Black
  // Node: Red, Children: Black
  // Rotation Property

 public:
  RBTree() : nil(0), root(&nil) {
    nil.red = false;
    nil.left = nullptr;
    nil.right = nullptr;
    nil.parent = nullptr;
  }

  void insertNode(int val) {
    Node* new_node = new Node(val);
    new_node->left = &nil;
    new_node->right = &nil;
    new_node->red = true;
    new_node->parent = nullptr;

    Node* parent = nullptr;
    Node* current = root;

    while (current != &nil) {
      parent = current;

      if (val < current->val) {
        current = current->left;
      } else if (val > current->val) {
        current = current->right;
      } else {
        delete new_node;  // duplicate
        return;
      }
    }

    new_node->parent = parent;

    if (parent == nullptr) {
      root = new_node;
    } else if (val < parent->val) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }
    fixInsert(new_node);
  }

  void fixInsert(Node* curr) {
    while (curr != root && curr->parent->red) {
      Node* parent = curr->parent;
      Node* grandparent = parent->parent;

      if (parent == grandparent->right) {
        Node* uncle = grandparent->left;

        if (uncle->red) {
          parent->red = false;
          uncle->red = false;
          grandparent->red = true;
          curr = grandparent;
        } else {
          if (curr == parent->left) {
            curr = parent;
            rotateRight(curr);
          }

          parent = curr->parent;
          grandparent = parent->parent;

          parent->red = false;
          grandparent->red = true;

          rotateLeft(grandparent);
        }
      } else {
        Node* uncle = grandparent->right;

        if (uncle->red) {
          parent->red = false;
          uncle->red = false;
          grandparent->red = true;
          curr = grandparent;
        } else {
          if (curr == parent->right) {
            curr = parent;
            rotateLeft(curr);
          }

          parent = curr->parent;
          grandparent = parent->parent;

          parent->red = false;
          grandparent->red = true;

          rotateRight(grandparent);
        }
      }
    }

    root->red = false;
  }

  void rotateLeft(Node* pivot_parent) {
    if (pivot_parent == &nil || pivot_parent->right == &nil) {
      return;
    }
    Node* pivot = pivot_parent->right;
    pivot_parent->right = pivot->left;
    if (pivot->left != &nil) {
      pivot->left->parent = pivot_parent;
    }
    pivot->parent = pivot_parent->parent;
    if (pivot_parent == root) {
      root = pivot;
    } else if (pivot_parent == pivot_parent->parent->left) {
      pivot_parent->parent->left = pivot;
    } else {
      pivot_parent->parent->right = pivot;
    }
    pivot->left = pivot_parent;
    pivot_parent->parent = pivot;
  }

  void rotateRight(Node* pivot_parent) {
    if (pivot_parent == &nil || pivot_parent->left == &nil) {
      return;
    }
    Node* pivot = pivot_parent->left;
    pivot_parent->left = pivot->right;
    if (pivot->right != &nil) {
      pivot->right->parent = pivot_parent;
    }
    pivot->parent = pivot_parent->parent;
    if (pivot_parent == root) {
      root = pivot;
    } else if (pivot_parent == pivot_parent->parent->left) {
      pivot_parent->parent->left = pivot;
    } else {
      pivot_parent->parent->right = pivot;
    }
    pivot->right = pivot_parent;
    pivot_parent->parent = pivot;
  }

  int getHeight() { return getHeight(root); }
  std::vector<int> preorder() {
    std::vector<int> visited;
    preorder(root, visited);
    return visited;
  }

 private:
  Node nil;
  Node* root;

  int getHeight(Node* node) {
    if (node == &nil) {
      return -1;
    }

    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
  }

  void preorder(Node* node, std::vector<int>& visited) {
    if (node == &nil) {
      return;
    }

    visited.push_back(node->val);

    preorder(node->left, visited);
    preorder(node->right, visited);
  }
};

auto main() -> int {
  RBTree tree;
  tree.insertNode(10);
  tree.insertNode(20);
  tree.insertNode(30);
  tree.insertNode(40);
  tree.insertNode(50);
  std::cout << tree.getHeight() << '\n';
  std::vector<int> values = tree.preorder();
  for (int v : values) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
  return 0;
}

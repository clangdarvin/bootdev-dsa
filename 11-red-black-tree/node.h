#pragma once

#include <algorithm>
class Node {
 public:
  bool red;
  Node* parent;
  Node* left;
  Node* right;
  int val;

  explicit Node(int value = 0)
      : red(false),
        parent(nullptr),
        left(nullptr),
        right(nullptr),
        val(value) {}
};

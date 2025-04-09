#ifndef __SRC_MODEL_DIALOGTREE_H__
#define __SRC_MODEL_DIALOGTREE_H__

#include "Choice.h"
#include <iostream>
#include <vector>

class DialogTree {
private:
  struct Node {
    Choice value;
    Node *parent = nullptr;
    Node *child = nullptr;
    Node() = default;
  };
  Node *root = nullptr;
  Node *pointer = nullptr;

public:
  // ~DialogTree();  // to do
  Choice getPointerValue();
  bool isPointerNull();
  void pointerToChild();
  void pointerToParent();
  void pointerToRoot();
  void addChild(Choice newEl);
  void printTree();
private:
  void printTreeRecursive(Node* node, int depth);
};

#endif // __SRC_MODEL_DIALOGTREE_H__

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
    std::vector<Node*> children;
    Node() = default;
    Node(Choice val) {
      value = val;
    }
    Node(Choice val,Node* ptr) {
      value = val;
      parent = ptr;
    }
  };
  Node *root = nullptr;
  Node *pointer = nullptr;

public:
  // ~DialogTree();  // to do
  Choice getPointerValue();
  bool isPointerNull();
  void pointerToChild(unsigned index);
  void pointerToParent();
  void pointerToRoot();
  void addChild(Choice newEl);
  void printTree();
  std::vector<std::string> getChildrenChoiceDesc();
private:
  void printTreeRecursive(Node* node, int depth);
};

#endif // __SRC_MODEL_DIALOGTREE_H__

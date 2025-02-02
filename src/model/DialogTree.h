#ifndef __SRC_MODEL_DIALOGTREE_H__
#define __SRC_MODEL_DIALOGTREE_H__

#include "Choice.h"
#include <iostream>

class DialogTree {
private:
  struct Node {
    Choice value;
    Node *parent = nullptr;
    Node *child = nullptr;
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
};

#endif // __SRC_MODEL_DIALOGTREE_H__

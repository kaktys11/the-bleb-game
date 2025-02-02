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
  Choice getPointerValue();
  bool isPointerNull();
  void pointerToChild();
  void addChild(Choice newEl);
  void printTree();
};

#endif // __SRC_MODEL_DIALOGTREE_H__

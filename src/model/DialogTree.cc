#include "DialogTree.h"

Choice DialogTree::getPointerValue() {
  if (pointer == nullptr) {
    throw std::runtime_error("pointer is nullpointer");
  }
  return pointer->value;
}

bool DialogTree::isPointerNull() {
  if (pointer == nullptr) {
    return true;
  } else {
    return false;
  };
}

void DialogTree::pointerToChild() {
  if (pointer == nullptr) {
    throw std::runtime_error("pointer is nullpointer");
  } else {
    pointer = pointer->child;
  }
}

void DialogTree::addChild(Choice newEl) { // to do type parent insert
  if (root == nullptr) {
    pointer = new Node;
    root = pointer;
    pointer->value = newEl;
  } else {
    pointer->child = new Node;
    pointer->child->value = newEl;
  }
}

void DialogTree::printTree() {
  Node *print_pointer = root; // = ????
  while (print_pointer != nullptr) {
    std::cout << print_pointer->value << std::endl;
    print_pointer = print_pointer->child;
  }
}

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

void DialogTree::pointerToChild(unsigned index) {
  if (pointer == nullptr) {
    throw std::runtime_error("pointer is nullpointer");
  }
  if (index < 0 || index >= pointer->children.size()) { // additional
    throw std::runtime_error("children scene index out of range");
  }
  pointer = pointer->children[index];
}

void DialogTree::pointerToParent() {
  if (pointer == nullptr) {
    throw std::runtime_error("pointer is nullpointer");
  }
  pointer = pointer->parent;
}

void DialogTree::pointerToRoot() { pointer = root; }

void DialogTree::addChild(Choice newEl) { // to do multichildren
  if (root == nullptr) {
    pointer = new Node;
    root = pointer;
    pointer->value = newEl;
  } else {
    if (pointer == nullptr) {
      throw std::runtime_error("pointer is nullpointer");
    }
    pointer->children.push_back(new Node(newEl, pointer));
  }
}

void DialogTree::printTree() {
  printTreeRecursive(root, 0);
}

void DialogTree::printTreeRecursive(Node* node, int depth) {
  if (!node) return;

  std::cout << std::string(depth * 2, ' ') << "- " << node->value.getHeader() << std::endl;

  for (const auto& children : node->children) {
    printTreeRecursive(children, depth + 1);
  }
  // printTreeRecursive(root, 0);
}

void DialogTree::printTreeRecursive(Node* node, int depth) {
  if (!node) return;

  std::cout << std::string(depth * 2, ' ') << "- " << node->value.getHeader() << std::endl;

  for (const auto& children : node->children) {
    printTreeRecursive(children, depth + 1);
  }
}


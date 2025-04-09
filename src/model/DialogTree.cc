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
  }
  pointer = pointer->child;
}

void DialogTree::pointerToParent() {
  if (pointer == nullptr) {
    throw std::runtime_error("pointer is nullpointer");
  }
  pointer = pointer->parent;
}

void DialogTree::pointerToRoot() { pointer = root; }

void DialogTree::addChild(Choice newEl) { // to do multichild
  if (root == nullptr) {
    pointer = new Node;
    root = pointer;
    pointer->value = newEl;
  } else {
    if (pointer == nullptr) {
      throw std::runtime_error("pointer is nullpointer");
    }
    if (pointer->child != nullptr) {
      throw std::runtime_error("this node already has a child");
    }
    pointer->child = new Node;
    pointer->child->value = newEl;
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
}

std::vector<std::string> DialogTree::getChildrenChoiceDesc() {
  if (pointer == nullptr) {
    throw std::runtime_error("pointer is nullpointer");
  }
  std::vector<std::string> result;
  for (unsigned i = 0; i < pointer->children.size(); ++i) {
    result.push_back(pointer->children[i]->value.getChoiceDesc());
  }
  return result;
}

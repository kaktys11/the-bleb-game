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
  if (index >= pointer->children.size()) {
    throw std::runtime_error("index too large");
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

void DialogTree::addChild(Choice newEl) { // to do multichild
  if (root == nullptr) {
    pointer = new Node(newEl);
    root = pointer;
  } else {
    if (pointer == nullptr) {
      throw std::runtime_error("pointer is nullpointer");
    }
    pointer->children.push_back(new Node(newEl,pointer));
  }
}

void DialogTree::printTree() {
  // Node *print_pointer = root; // = ????
  // while (print_pointer != nullptr) {
  //   std::cout << print_pointer->value << std::endl;
  //   print_pointer = print_pointer->child;
  // }
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
  std::vector<std::string> childrenDesc;
  for (unsigned i = 0; i < pointer -> children.size();i++) {
    childrenDesc.push_back(pointer->children[i]->value.getChoiceDesc());
  }
  return childrenDesc;
}
#include <iostream>
#include "model/Choice.h"

class Character {
 private:
/*
0 = очень плохая карма
1 = плохая карма
2 = не очень плохая карма
3 = нейтральная карма(изначальное значение)
4 = не очень хорошая карма
5 = хорошая карма
6 = очень хорошая карма
*/
  int karma = 3;

 public:
  void increaseKarma() {
    if (karma < 6) {
      karma++;
    }
  }
  void decreaseKarma() {
    if (karma > 0) {
      karma--;
    }
  }
};

class Manager {
 private:
  Character character;
};

struct Node {
int value;
Node* parent = nullptr;
Node* child = nullptr;
};

class DialogTree {
Node* root = nullptr;
Node* pointer = nullptr;
public:

  int getPointerValue() {
    if (pointer == nullptr) {
      throw std::runtime_error("pointer is nullpointer");
    }
    return pointer->value;
  };

  bool isPointerNull() {
    if (pointer == nullptr) {
      return true;
    } else {
      return false;
    };
  };

  void pointerToChild() {
    if (pointer == nullptr) {
      throw std::runtime_error("pointer is nullpointer");
    } else {
      pointer = pointer->child;
    }
  }

  void add_element(int newEl) {//to do type parent insert
    if (root == nullptr) {
      pointer = new Node;
      root = pointer;
      pointer->value = newEl;
    } else {
      pointer->child = new Node;
      pointer->child->value = newEl;
    }
  };
  void print_tree() {
    Node* print_pointer = root;  // = ????
    while (print_pointer != nullptr) {
      std::cout << print_pointer->value<< std::endl;
      print_pointer = print_pointer->child;
    }
  };

};

int main() {
  // Choice test;
  // test.getHeader();
  // std::cout << test.getHeader() << std::endl;
  DialogTree three;
  // three.getPointerValue();
  three.add_element(3);
  three.print_tree();
  // Node* element_1 = new Node;
  // element_1->value = 3;
  // Node* element_2 = new Node;
  // element_2->value = 5;
  // Node* element_3 = new Node;
  // element_3->value = 7;
  // element_1->child = element_2;
  // element_2->child = element_3;
  // element_2->parent = element_1;
  // element_3->parent = element_2;



  // Node* pointer = element_1;
  // while (pointer != nullptr) {
  //   std::cout << (*pointer).value<< std::endl;
  //   pointer = (*pointer).child;
  // }
  // delete element_1;
  // delete element_2;
  // delete element_3;
}

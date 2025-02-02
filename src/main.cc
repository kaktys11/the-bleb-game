#include "model/Choice.h"
#include "model/DialogTree.h"
#include <iostream>

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

int main() {
  // Choice test;
  // test.getHeader();
  // std::cout << test.getHeader() << std::endl;
  DialogTree three;
  // three.getPointerValue();
  three.addChild(Choice("hi", "hello", "there"));
  three.printTree();
  // three.print_tree();
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

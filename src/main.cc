#include <iostream>
#include "model/Choice.h"
#include "model/DialogTree.h"

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
  DialogTree three;
  three.addChild(Choice("hi", "hello", "hey there"));
  three.printTree();
}

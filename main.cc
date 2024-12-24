#include <iostream>

class Character {
 private:
/*
0 = очень плохая карма
1= плохая карма
2 = не очень плохая карма
3 = нейтральная карма(изначальное значение)
4 = не очень хорошая карма
5 =хорошая карма
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

class Choice {
  private:
  std::string header;
  std::string description;
  std::string choiceDesc;
  public:
  std::string getHeader() {
    return header;
  }
  std::string setHeader(std::string value) {
    header=value
  }
  std::string getDescription() {
    return description;
  }
  std::string setDescription(std::string value) {
    description=value
  }
std::string getChoiceDesc() {
    return coiceDesc;
  }
  std::string setChoiceDesc(std::string value) {
    choiceDesc=value
  }
}

int main() {
  Choice test;
  test.setHeader("sus");
    std::cout << "hello world";
}
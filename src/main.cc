#include "model/Choice.h"
#include "model/DialogTree.h"
#include <iostream>
#include "raylib.h"

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
  Choice test("в замке","you go to the castle and see a cow what do you do","go to the castle");
  InitWindow(800,600,"OKNO");
  Font font = LoadFont("src/assets/advanced_pixel-7.ttf");
  Color colour = PINK;
  while(WindowShouldClose() == false) {
    BeginDrawing();
    ClearBackground(colour);
    //DrawText(test.getHeader().c_str(),40,70,22,BLACK);
    DrawTextEx(font,test.getHeader().c_str(), {40,70},60,7,BLACK);
    //DrawText(test.getDescription().c_str(),40,100,15,BLACK);
    //DrawTextEx(font,test.getDescription(), Vector2 position, float fontSize, float spacing, Color tint)
    EndDrawing();
    if (IsKeyPressed(KEY_UP)) {
      if (colour == VIOLET) {
        colour = PINK;
      } else {
        colour = VIOLET;
      }
    }
  }
  CloseWindow();
  // DialogTree three;
  // three.addChild(Choice("hi", "hello", "hey there"));
  // three.printTree();
}

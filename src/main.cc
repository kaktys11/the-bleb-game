#include "model/Choice.h"
#include "model/DialogTree.h"
#include <iostream>
#include <QMainWindow>
#include <QApplication>
// #include "raylib.h"

// class Character {
// private:
//   /*
//   0 = очень плохая карма
//   1 = плохая карма
//   2 = не очень плохая карма
//   3 = нейтральная карма(изначальное значение)
//   4 = не очень хорошая карма
//   5 = хорошая карма
//   6 = очень хорошая карма
//   */
//   int karma = 3;

// public:
//   void increaseKarma() {
//     if (karma < 6) {
//       karma++;
//     }
//   }
//   void decreaseKarma() {
//     if (karma > 0) {
//       karma--;
//     }
//   }
// };

// class Manager {
// private:
//   Character character;
// };

// bool isColourEqual(Color colour,Color colour2) {
//   if (colour.b==colour2.b && colour.r==colour2.r && colour.g==colour2.g && colour.a==colour2.a) {
//     return true;
//   } else {
//     return false;
//   }
// };

// class Button {
//   public:
//   Button() {}
//   Button(Rectanle rect) {

//   }
//   bool isButtonPressed() {
//     if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
//     CheckCollisionPointRec(GetMousePosition(),buttonRect))
//     {
//       return true;
//     }else {
//       return false;0.

//     }
//   }
//   void draw() {\
//   DrawRectangleRec(buttonRect,buttonColour);
// }
//   void update() {
//     if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
//     CheckCollisionPointRec(GetMousePosition(),buttonRect))
//     {
//       buttonColour.r+=10;
//     }
//   }
//   private:
//   Rectangle buttonRect = {1,9,400,100};
//   Color buttonColour = {1,4,8,255};
// };

// class DialogButton {
// private:
// int buttonNumber = 3;
// }

class GameMainWindow : public QMainWindow {
  public:
    GameMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
      setWindowTitle("Bleb Game");
      setGeometry(100, 100, 300, 200);
    }
}

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  GameMainWindow window;
  window.show();
  return app.exec();
}

// int main() {
//   Choice test("в замке","you go to the castle and see a cow what do you do","go to the castle");
//   InitWindow(800,600,"OKNO");
//   Font font = LoadFont("src/assets/advanced_pixel-7.ttf");
//   Color colour = PINK;
//   Button button;
//   while(WindowShouldClose() == false) {
//     BeginDrawing();
//     ClearBackground(colour);
//     //DrawText(test.getHeader().c_str(),40,70,22,BLACK);
//     DrawTextEx(font,test.getHeader().c_str(), {40,70},60,7,BLACK);
//     //DrawText(test.getDescription().c_str(),40,100,15,BLACK);
//     //DrawTextEx(font,test.getDescription(), Vector2 position, float fontSize, float spacing, Color tint)
//     button.draw();
//     EndDrawing();
//     button.update();
//     if (IsKeyPressed(KEY_UP)) {
//       if (isColourEqual(colour,VIOLET) == true) {
//         colour = PINK;
//       } else {
//         colour = VIOLET;
//       }
//     }
//   }
//   CloseWindow();
//   // DialogTree three;
//   // three.addChild(Choice("hi", "hello", "hey there"));
//   // three.printTree();
// }

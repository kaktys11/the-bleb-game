#include "model/Choice.h"
#include "model/DialogTree.h"
#include "view/DialogOptions.h"
#include <iostream>
#include <vector>
#include <QMainWindow>
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QFontDatabase>
#include <QFile>
#include <QTextStream>

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

void checkFileExists(const QString &filePath) {
    if (QFile::exists(filePath)) {
        qDebug() << "The file exists at" << filePath;
    } else {
        qDebug() << "The file does NOT exist at" << filePath;
    }
}


class GameMainWindow : public QMainWindow {
  public:
    GameMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
      QFontDatabase fontDatabase;
      int fontId = fontDatabase.addApplicationFont(":/assets/fonts/Inverkrug.otf");  // Adjust path to your font file
      if (fontId == -1) {
        qDebug() << "font not loaded";
      } else {
        QString fontFamily = fontDatabase.applicationFontFamilies(fontId).at(0);

        // Set font for the application
        QFont font(fontFamily);
        setFont(font);
      }
      setWindowTitle("Bleb Game");
      int screenWidth = 1920;
      int screenHeight = 1080;
      int windowWidth = 1400;
      int windowHeight = 500;
      setGeometry((screenWidth - windowWidth) / 2, (screenHeight - windowHeight) / 2, windowWidth, windowHeight);

      QWidget* centralWidget = new QWidget();
      setCentralWidget(centralWidget);
      QVBoxLayout* layout = new QVBoxLayout(centralWidget);

      // QPushButton* button = new QPushButton("Knopka");
      // layout->addWidget(button);

      QLabel* labelName = new QLabel("название");
      labelName->setFrameStyle(QFrame::Panel | QFrame::Sunken);
      layout->addWidget(labelName);

      QLabel* labelPicture = new QLabel("картинка");
      labelPicture->setFrameStyle(QFrame::Panel | QFrame::Sunken);
      layout->addWidget(labelPicture);

      QLabel* labelDesc = new QLabel("название");
      labelDesc->setFrameStyle(QFrame::Panel | QFrame::Sunken);
      layout->addWidget(labelDesc);

      DialogOptions* optionWidget = new DialogOptions();
      layout->addWidget(optionWidget);
      optionWidget->setButtons({"1", "2"});
      connect(optionWidget, &DialogOptions::buttonPressed, [this](int buttonInd) {
        qDebug() << "index is " << buttonInd;
      });
      optionWidget->setButtons({"hi", "направо"});
    };
};

int main(int argc, char** argv) {
  QApplication app(argc, argv);


  int fontId = QFontDatabase::addApplicationFont(":/assets/fonts/advanced_pixel-7.ttf");
  if (fontId == -1) {
    qWarning("Failed to load font");
    return -1;
  }

  // Get the font family name (e.g., "My Custom Font")
  QStringList families = QFontDatabase::applicationFontFamilies(fontId);
  if (families.isEmpty()) {
    qWarning("Font loaded but no families found");
    return -1;
  }

  QString fontFamily = families.at(0);
  QFile file(":/assets/style.qss"); // Use ":/..." for resources, or just "style.qss" for file on disk
  if (file.open(QFile::ReadOnly | QFile::Text)) {
    QTextStream stream(&file);
    QString stylesheet = stream.readAll();

    stylesheet += QString("\nQWidget { font-family: \"%1\"; }").arg(fontFamily);
    app.setStyleSheet(stylesheet);
  } else {
    qWarning("Could not open stylesheet file.");
  }


  GameMainWindow window;
  window.show();
  return app.exec();
};







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

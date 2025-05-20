#ifndef __SRC_VIEW_DIALOGOPTIONS_H__
#define __SRC_VIEW_DIALOGOPTIONS_H__

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QFont>
#include <QFontDatabase>

class DialogOptions : public QWidget {
  Q_OBJECT
 signals:
  void buttonPressed(int buttonIndex);
 private:
  QFont font;
 public:
  DialogOptions(QWidget *parent = nullptr)  : QWidget(parent) {
    QFontDatabase fontDatabase;
    int fontId = fontDatabase.addApplicationFont(":/assets/fonts/advanced_pixel-7.ttf");  // Adjust path to your font file
    if (fontId == -1) {
      qDebug() << "font not loaded";
    }
    QString fontFamily = fontDatabase.applicationFontFamilies(fontId).at(0);
    QVBoxLayout* layoutDialog = new QVBoxLayout(this);
    font = QFont(fontFamily);
};

  void setButtons() { // std::vector<std::string> options
    QPushButton* buttonA = new QPushButton("option-a");
    layout()->addWidget(buttonA);
    QPushButton* buttonB = new QPushButton("option-b");
    layout()->addWidget(buttonB);
    QPushButton* buttonC = new QPushButton("option-c");
    layout()->addWidget(buttonC);
  }

  void setButtons(std::vector<std::string> options) {
    clearLayout();
    for (unsigned i = 0; i < options.size();i++) {
      QPushButton* button = new QPushButton(options[i].c_str());
      layout()->addWidget(button);
      // button->setStyleSheet(R"(
      //     QPushButton {
      //         background-color: #000000;  /* White background */
      //         color: #ffffff;             /* Black text */
      //         font-size: 30px;            /* Make the font big enough */
      //         border: 3px solid #ffffff;  /* Black border around the button */
      //         border-radius: 0px;        /* Rounded corners */
      //         padding: 10px 20px;         /* Spacing inside the button */
      //         min-width: 150px;           /* Minimum width */
      //         min-height: 20px;           /* Minimum height */
      //         text-align: left;         /* Center the text */
      //     }

      //     QPushButton:hover {
      //         background-color: #FF6F00;  /* Orange-ish color when hovered */
      //         border: 3px solid #ffffff;  /* Keep border */
      //     }

      //     QPushButton:pressed {
      //         background-color: #FF4500;  /* Darker orange when clicked */
      //     }
      // )");
      button->setFont(font);
      connect(button, &QPushButton::clicked, [this, i]() {
        emit buttonPressed(i);
      });
    }
  }

  void clearLayout() {
    QLayoutItem* item = layout()->takeAt(0);
    while (item != nullptr) {
      QWidget* widget = item->widget();
      if (widget) {
        delete widget;
      }
      delete item;
      item = layout()->takeAt(0);
    }

  }


};

#endif  // __SRC_VIEW_DIALOGOPTIONS_H__

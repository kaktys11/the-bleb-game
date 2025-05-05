#ifndef __SRC_VIEW_DIALOGOPTIONS_H__
#define __SRC_VIEW_DIALOGOPTIONS_H__

#include <QWidget>
#include <QPushButton>
#include <QLayout>

class DialogOptions : public QWidget {
  Q_OBJECT
 signals:
  void buttonPressed(int buttonIndex);
 public:
  DialogOptions(QWidget *parent = nullptr)  : QWidget(parent) {
  QVBoxLayout* layoutDialog = new QVBoxLayout(this);
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

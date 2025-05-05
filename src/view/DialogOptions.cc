#include "DialogOptions.h"

DialogOptions::DialogOptions(QWidget *parent = nullptr) : QWidget(parent) {
  QVBoxLayout* layoutDialog = new QVBoxLayout(this);
};


void DialogOptions::setButtons() { // std::vector<std::string> options
  QPushButton* buttonA = new QPushButton("option-a");
  layout()->addWidget(buttonA);
  QPushButton* buttonB = new QPushButton("option-b");
  layout()->addWidget(buttonB);
  QPushButton* buttonC = new QPushButton("option-c");
  layout()->addWidget(buttonC);
}

void DialogOptions::setButtons(std::vector<std::string> options) {
  clearLayout();
  for (unsigned i = 0; i < options.size();i++) {
    QPushButton* button = new QPushButton(options[i].c_str());
    layout()->addWidget(button);
    // connect(button, &QPushButton::clicked, [this, i]() {
    //   emit buttonPressed(i);
    // });
  }
}


void DialogOptions::clearLayout() {
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

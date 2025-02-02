#include "Choice.h"

std::string Choice::getHeader() {
  return header;
}

void Choice::setHeader(std::string value) {
  header=value;
}

std::string Choice::getDescription() {
  return description;
}

void Choice::setDescription(std::string value) {
  description=value;
}

std::string Choice::getChoiceDesc() {
  return choiceDesc;
}

void Choice::setChoiceDesc(std::string value) {
  choiceDesc=value;
}

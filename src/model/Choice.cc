#include "Choice.h"

Choice::Choice() : header(""), description(""), choiceDesc("") {}

Choice::Choice(const std::string &h, const std::string &d, const std::string &c)
    : header(h), description(d), choiceDesc(c) {}

Choice::Choice(const Choice &other)
    : header(other.header), description(other.description),
      choiceDesc(other.choiceDesc) {}

Choice::Choice(Choice &&other) noexcept
    : header(std::move(other.header)),
      description(std::move(other.description)),
      choiceDesc(std::move(other.choiceDesc)) {
  other.header = "";
  other.description = "";
  other.choiceDesc = "";
}

Choice &Choice::operator=(const Choice &other) {
  if (this != &other) {
    header = other.header;
    description = other.description;
    choiceDesc = other.choiceDesc;
  }
  return *this;
}

Choice &Choice::operator=(Choice &&other) noexcept {
  if (this != &other) {
    header = std::move(other.header);
    description = std::move(other.description);
    choiceDesc = std::move(other.choiceDesc);

    other.header = "";
    other.description = "";
    other.choiceDesc = "";
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Choice &choice) {
  os << "Header:             " << choice.getHeader() << "\n";
  os << "Description:        " << choice.getDescription() << "\n";
  os << "Choice Description: " << choice.getChoiceDesc() << "\n";
  return os;
}

std::string Choice::getHeader() const { return header; }

void Choice::setHeader(std::string value) { header = value; }

std::string Choice::getDescription() const { return description; }

void Choice::setDescription(std::string value) { description = value; }

std::string Choice::getChoiceDesc() const { return choiceDesc; }

void Choice::setChoiceDesc(std::string value) { choiceDesc = value; }

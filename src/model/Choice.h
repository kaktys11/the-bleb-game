#ifndef __SRC_MODEL_CHOICE_H__
#define __SRC_MODEL_CHOICE_H__

#include <string>

class Choice {
 private:
  std::string header;
  std::string description;
  std::string choiceDesc;
 public:
  std::string getHeader();
  void setHeader(std::string value);
  std::string getDescription();
  void setDescription(std::string value);
  std::string getChoiceDesc();
  void setChoiceDesc(std::string value);
};

#endif  // __SRC_MODEL_CHOICE_H__

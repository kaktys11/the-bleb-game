#ifndef __SRC_MODEL_CHOICE_H__
#define __SRC_MODEL_CHOICE_H__

class Choice;

class Choice {
 private:
  std::string header;
  std::string description;
  std::string choiceDesc;
 public:
  std::string getHeader() {
    return header;
  }
  // std::string setHeader(std::string value) {
  //   header=value
  // }
  // std::string getDescription() {
  //   return description;
  // }
  // std::string setDescription(std::string value) {
  //   description=value
  // }
  // std::string getChoiceDesc() {
  //   return coiceDesc;
  // }
  // std::string setChoiceDesc(std::string value) {
  //   choiceDesc=value
  // }
};

#endif  // __SRC_MODEL_CHOICE_H__

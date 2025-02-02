#ifndef __SRC_MODEL_CHOICE_H__
#define __SRC_MODEL_CHOICE_H__

#include <string>
#include <iostream>

class Choice {
private:
  std::string header;
  std::string description;
  std::string choiceDesc;

public:
  Choice();
  Choice(const std::string &h, const std::string &d, const std::string &c);
  Choice(const Choice &other);
  Choice(Choice &&other) noexcept;
  ~Choice() = default;
  Choice &operator=(const Choice &other);
  Choice &operator=(Choice &&other) noexcept;
  friend std::ostream &operator<<(std::ostream &os, const Choice &choice);

  std::string getHeader() const;
  void setHeader(std::string value);
  std::string getDescription() const;
  void setDescription(std::string value);
  std::string getChoiceDesc() const;
  void setChoiceDesc(std::string value);
};

#endif // __SRC_MODEL_CHOICE_H__

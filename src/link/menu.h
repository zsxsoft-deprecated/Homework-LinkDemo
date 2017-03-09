//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//
#ifndef LINK_MENU_H_
#define LINK_MENU_H_

#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace link {

typedef std::function<void(void)> TMenuFunction;
typedef struct MenuData {
  char input_key;
  std::string input_string;
  TMenuFunction function_pointer;
} MenuData;

class Menu {
 public:
  Menu();
  static std::shared_ptr<Menu> GetInstance();
  void Append(char, std::string, TMenuFunction);
  void Print(void);
  void Read(void);
  void Hello(void);

 private:
  static std::shared_ptr<Menu> Instance;
  std::vector<MenuData> menus;
  void PrintCurrentTime();
};
}  // namespace link
#endif  // LINK_MENU_H_

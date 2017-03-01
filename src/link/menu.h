//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//
#ifndef LINK_MENU_H_
#define LINK_MENU_H_
#include <string>
#include <vector>
namespace link {
using std::string;
using std::vector;

typedef struct MenuData {
  char input_key;
  std::string input_string;
  void (*function_pointer)(void);
} MenuData;

class Menu {
 public:
  Menu();
  static void Append(char, string, void (*function_pointer)(void));
  static void Print(void);
  static void Read(void);
  static void Hello(void);

 private:
  static vector<MenuData> *menus;
  static void PrintCurrentTime();
};
}  // namespace link
#endif  // LINK_MENU_H_

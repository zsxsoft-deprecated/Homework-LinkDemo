//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//
#include "menu.h"
#include <iostream>
namespace link {

using std::cout;
using std::cin;
using std::endl;
using std::string;

Menu::Menu() {
  return;
}
vector<MenuData> *Menu::menus;
void Menu::Append(
    char input_key, string input_string, void (*function_pointer)(void)
) {
  if (menus == NULL) menus = new vector<MenuData>();
  MenuData *temp = new MenuData;
  temp->input_key = input_key;
  temp->input_string = input_string;
  temp->function_pointer = function_pointer;
  (*menus).push_back(*temp);
}

void Menu::Hello() {
  PrintCurrentTime();
}

void Menu::PrintCurrentTime() {
  struct tm *time_info = new tm;
  time_t raw_time = time(NULL);
  time_info = localtime_r(&raw_time, time_info);

  cout << "Created by zsx as his homework." << endl << endl;
  cout << "现在是：" << time_info->tm_year + 1900 << " 年 ";
  cout << time_info->tm_mon + 1 << " 月 ";
  cout << time_info->tm_mday << " 日 ";
  cout << time_info->tm_hour << ":";
  cout << time_info->tm_min << ":";
  cout << time_info->tm_sec << std::endl;

  delete time_info;
}

void Menu::Print(void) {
  if (menus == NULL) menus = new vector<MenuData>();
  cout << "****************************************" << endl;
  for (auto menu : (*menus)) {
    cout << "*   " << menu.input_key;
    cout << "：    " << menu.input_string;
    cout << endl;
  }
  cout << "****************************************" << endl;
}

void Menu::Read(void) {
  if (menus == NULL) menus = new vector<MenuData>();
  char input_key;
  while (1) {
    int flag = 1;
    Print();
    cout << "请选择：( ";
    for (auto menu : (*menus)) {
      cout << menu.input_key << " ";
    }
    cout << ")：";
    std::cin >> input_key;
    if (input_key == '\0') break;  // To prevent endless loop warning
    if (input_key >= 'a') {  // convert lower case to upper case
      input_key -= ('a' - 'A');
    }
    for (auto menu : (*menus)) {
      if (menu.input_key == input_key) {
        flag = 0;
        menu.function_pointer();
      }
    }
    if (flag == 1) {
      cout << "格式错误，请重新输入！" << endl;
    }
  }
}

}  // namespace link

//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//
#include "menu.h"

#include <iostream>

namespace link {

std::shared_ptr<std::vector<MenuData>> Menu::menus;
Menu::Menu() {
}
/**
 * Append to menu
 * @param input_key
 * @param input_string
 * @param function_pointer
 */
void Menu::Append(
    char input_key, std::string input_string, void (*function_pointer)(void)
) {
  if (menus == NULL) menus = std::make_shared<std::vector<MenuData>>();
  auto temp = std::make_shared<MenuData>();
  temp->input_key = input_key;
  temp->input_string = input_string;
  temp->function_pointer = function_pointer;
  (*menus).push_back(*temp);
}

/**
 * Say hello
 */
void Menu::Hello() {
  PrintCurrentTime();
}

/**
 * Print current time
 */
void Menu::PrintCurrentTime() {
  using std::cout;
  using std::endl;

  auto *time_info = new tm;
  auto raw_time = time(NULL);
  time_info = localtime_r(&raw_time, time_info);

  cout << "Created by zsx as his homework." << endl << endl;
  cout << "现在是：" << time_info->tm_year + 1900 << " 年 ";
  cout << time_info->tm_mon + 1 << " 月 ";
  cout << time_info->tm_mday << " 日 ";
  cout << time_info->tm_hour << ":";
  cout << time_info->tm_min << ":";
  cout << time_info->tm_sec << endl;

  delete time_info;
}

/**
 * Print menu items
 */
void Menu::Print(void) {
  using std::cout;
  using std::endl;

  if (menus == NULL) menus = std::make_shared<std::vector<MenuData>>();
  cout << "****************************************" << endl;
  for (auto menu : (*menus)) {
    cout << "*   " << menu.input_key;
    cout << "：    " << menu.input_string;
    cout << endl;
  }
  cout << "****************************************" << endl;
}

/**
 * Print menu and read fron stdin
 */
void Menu::Read(void) {
  using std::cin;
  using std::cout;
  using std::endl;

  if (menus == NULL) menus = std::make_shared<std::vector<MenuData>>();
  char input_key;
  while (1) {
    int flag = false;
    Print();
    cout << "请选择：( ";
    for (auto menu : (*menus)) {
      cout << menu.input_key << " ";
    }
    cout << ")：";
    cin >> input_key;
    if (input_key == '\0') break;  // To prevent endless loop warning
    if (input_key >= 'a') {  // convert lower case to upper case
      input_key -= ('a' - 'A');
    }
    for (auto menu : (*menus)) {
      if (menu.input_key == input_key) {
        flag = true;
        menu.function_pointer();
      }
    }
    if (!flag) {
      cout << "格式错误，请重新输入！" << endl;
    }
  }
}

}  // namespace link

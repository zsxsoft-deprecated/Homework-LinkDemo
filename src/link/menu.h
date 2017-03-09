/*
 * Copyright 2017 zsx<zsx@zsxsoft.com>
 * Created by sx on 2/28/2017.
 * WTFPL License
 *
 * The definition of class Menu
 */

#ifndef LINK_MENU_H_
#define LINK_MENU_H_

#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace link {

/**
 * Class to display menu
 */
class Menu {
 public:
  typedef std::function<void(void)> TMenuFunction;
  typedef struct MenuData {
    char input_key;
    std::string input_string;
    TMenuFunction function_pointer;
  } MenuData;

  Menu();
  /**
   * Get the instance of Menu
   * @return instance
   */
  static std::shared_ptr<Menu> GetInstance();
  /**
   * Append to menu
   * @param input_key
   * @param input_string
   * @param function_pointer
   */
  void Append(char, std::string, TMenuFunction);
  /**
   * Print menu items
   */
  void Print(void);
  /**
   * Print menu and read from stdin
   */
  void Read(void);
  /**
   * Says Hello
   */
  void Hello(void);

 private:
  /**
   * Menu Instance
   */
  static std::shared_ptr<Menu> Instance;
  /**
   * Menus
   */
  std::vector<MenuData> menus;
  /**
   * Print current time
   */
  void PrintCurrentTime();
};
}  // namespace link
#endif  // LINK_MENU_H_

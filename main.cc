/*
 * Copyright 2017 zsx<zsx@zsxsoft.com>
 * Created by sx on 2/28/2017.
 * WTFPL License
 *
 * Just main entrance
 */

#include <iostream>

#include "src/link/io.h"
#include "src/link/menu.h"

using link::Menu;
using link::IO;

void ExitProgram(void) {
  exit(0);
}

int main(int argc, char** argv) {
  setlocale(LC_ALL, "zh_CN.UTF-8");
  auto io = IO::GetInstance();
  auto menu = Menu::GetInstance();
  menu->Append('C', "创建一个有2000个节点的(无序)链表", [io](){io->C();});
  menu->Append('O', "输出链表的前n个结点或整个链表所有结点的数据", [io](){io->O();});
  menu->Append('S', "将整个链表的数据都存入一个文件中", [io](){io->S();});
  menu->Append('X', "(分屏、加行号)显示链表数据文件的(全部)内容", [io](){io->X();});
  menu->Append('N', "显示（所有）不能构成合法日期的结点", [io](){io->N();});
  menu->Append('D', "删除链表的一堆结点", [io](){io->D();});
  menu->Append('I', "插入结点", [io](){io->I();});
  menu->Append('T', "显示链表每个结点的日期距离1900年1月1日的天数", [io](){io->T();});
  menu->Append('A', "链表按日期从小到大排序输出", [io](){io->A();});
  menu->Append('P', "统计并输出年月日都是素数的结点", [io](){io->P();});
  menu->Append('F', "链表翻转(不建立新的表来实现)", [io](){io->F();});
  menu->Append('Q', "退出", ExitProgram);
  menu->Hello();
  menu->Read();
  return 0;
}

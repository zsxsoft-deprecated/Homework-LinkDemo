//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//

#ifndef LINK_IO_H_
#define LINK_IO_H_
#include "date.h"
#include <cstdlib>
#include <ctime>
#include "list.h"
namespace link {
class IO {
 public:
  static List<Date> *LinkedList;
  static void C(void);
  static void O(void);
  static void N(void);
  static void F(void);
  static void T(void);
  static void D(void);
  static void P(void);
  static void A(void);
  static void I(void);
  static void S(void);
  static void X(void);
  static void CreateList(void);
 private:
  static void CreateNodes(const int number);
};
}  // namespace link
#endif  // LINK_IO_H_

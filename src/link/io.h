//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//

#ifndef LINK_IO_H_
#define LINK_IO_H_

#include "date.h"

#include <cstdlib>
#include <ctime>
#include <memory>

#include "list.h"

namespace link {
class IO {
 public:
  static std::unique_ptr<List<std::shared_ptr<Date>>> LinkedList;
  static void A(void);
  static void C(void);
  static void D(void);
  static void F(void);
  static void I(void);
  static void O(void);
  static void N(void);
  static void P(void);
  static void S(void);
  static void T(void);
  static void X(void);
  static void CreateList(void);
 private:
  static void CreateNodes(const int number);
};
}  // namespace link
#endif  // LINK_IO_H_

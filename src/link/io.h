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
  std::unique_ptr<List<std::shared_ptr<Date>>> LinkedList;
  static std::shared_ptr<IO> GetInstance();
  void A(void);
  void C(void);
  void D(void);
  void F(void);
  void I(void);
  void O(void);
  void N(void);
  void P(void);
  void S(void);
  void T(void);
  void X(void);
  IO(void);
  ~IO(void);
 private:
  static std::shared_ptr<IO> Instance;
  void CreateNodes(const int number);
};
}  // namespace link
#endif  // LINK_IO_H_

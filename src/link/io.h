/*
 * Copyright 2017 zsx<zsx@zsxsoft.com>
 * Created by sx on 2/28/2017.
 * WTFPL License
 *
 * The definition of class IO
 */

#ifndef LINK_IO_H_
#define LINK_IO_H_

#include "date.h"

#include <cstdlib>
#include <ctime>
#include <memory>

#include "list.h"

namespace link {
/**
 * Class for Main IO
 * Singleton
 */
class IO {
 public:
  std::unique_ptr<List<std::shared_ptr<Date>>> LinkedList;
  /**
   * Get instance of IO
   * @return instance
   */
  static std::shared_ptr<IO> GetInstance();
  /**
   * Sorts list
   */
  void A(void);
  /**
   * Creates 2000 nodes
   */
  void C(void);
  /**
   * Deletes some nodes
   */
  void D(void);
  /**
   * Reverses list
   */
  void F(void);
  /**
   * Inserts current date as node to list
   */
  void I(void);
  /**
   * Prints all nodes
   */
  void O(void);
  /**
   * Prints invalid nodes
   */
  void N(void);
  /**
   * Prints if nodes's y/m/d are prime numbers
   */
  void P(void);
  /**
   * Save Link in memory to file
   */
  void S(void);
  /**
   * Prints all nodes' distance to 1900-1-1
   */
  void T(void);
  /**
   * Reads from file and output
   */
  void X(void);
  IO(void);
  ~IO(void);

 private:
  /**
   * Singleton Design Pattern
   * Menu Instance
   */
  static std::shared_ptr<IO> Instance;
  /**
   * Creates nodes
   * @param number number of nodes want to create
   */
  void CreateNodes(const int number);
};
}  // namespace link
#endif  // LINK_IO_H_

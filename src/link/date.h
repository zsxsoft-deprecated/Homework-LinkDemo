/*
 * Copyright 2017 zsx<zsx@zsxsoft.com>
 * Created by sx on 2/28/2017.
 * WTFPL License
 *
 * The definition of class Date
 */

#ifndef LINK_DATE_H_
#define LINK_DATE_H_

#include <iostream>

namespace link {
/**
 * Date Class
 */
class Date {
 public:
  Date();
  Date(int, int, int);
  /**
   * year
   */
  int year;
  /**
   * month
   */
  int month;
  /**
   * day
   */
  int day;
  /**
   * Return true when this date valid
   * @return
   */
  bool IsValid() const;
  /**
   * Return true when this year is leap year
   * @return
   */
  int IsLeapYear() const;
  /**
   * Return days from the first day of the year
   * @return
   */
  int DaysFromFirstDayOfYear() const;
  /**
   * Return true when y/m/d are all prime number
   * @return
   */
  bool IsAllPrime() const;
  /**
   * Return the days between two dates with operator reloading
   * @param c the other day
   * @return
   */
  int operator-(const Date &c) const;
  bool operator<(const Date &c) const;
  bool operator>(const Date &c) const;
  bool operator==(const Date &c) const;
};
/**
 * Compatible with STL stream
 * @param os
 * @param obj
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Date &obj);
}  // namespace link
#endif  // LINK_DATE_H_

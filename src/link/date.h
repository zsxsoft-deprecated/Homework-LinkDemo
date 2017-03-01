//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//

#ifndef LINK_DATE_H_
#define LINK_DATE_H_


#include <iostream>
namespace link {
class Date {
 public:
  Date();
  Date(int, int, int);
  int year;
  int month;
  int day;
  bool IsValid() const;
  int IsLeapYear() const;
  int DaysFromFirstDayOfYear() const;
  bool IsAllPrime() const;
  int operator-(const Date &c) const;
  bool operator<(const Date &c) const;
  bool operator>(const Date &c) const;
  bool operator==(const Date &c) const;
};

std::ostream &operator<<(std::ostream &os, const Date &obj);
}  // namespace link
#endif  // LINK_DATE_H_

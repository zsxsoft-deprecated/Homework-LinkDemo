//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//
#include "date.h"

#include <cmath>

namespace link {

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
/**
 * Compatible with STL stream
 * @param os
 * @param obj
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Date &obj) {
  os << obj.year << "-" << obj.month << "-" << obj.day;
  return os;
}

Date::Date() {
}

Date::Date(int m_year, int m_month, int m_day) {
  year = m_year;
  month = m_month;
  day = m_day;
}

/**
 * Return if a number is a prime number
 * @return
 */
bool IsPrime(int number) {
  if (number == 1 || number == 0 || number % 2 == 0) return false;
  int i;
  int sqrted = static_cast<int>(sqrt(static_cast<double>(number)));
  for (i = 2; i <= sqrted; i++)
    if (number % i == 0)
      break;
  return (i > sqrted);
}

/**
 * Return is or is not the leap year
 * @return
 */
int Date::IsLeapYear() const {
  return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

/**
 * Return y/m/d are all or not y/m/d prime number
 * @return
 */
bool Date::IsAllPrime() const {
  return IsPrime(year) && IsPrime(month) && IsPrime(day);
}

/**
 * Return the date is or is not valid
 * @return
 */
bool Date::IsValid() const {
  int max_day = days[month];
  if (month == 2 && IsLeapYear()) max_day++;
  if (month <= 0 || month > 12 || day <= 0) {
    return false;
  }
  return day <= max_day;
}

/**
 * Return days from the first day of the year
 * @return
 */
int Date::DaysFromFirstDayOfYear() const {
  int ret = 0;
  for (int i = 1; i < month; i++) {
    ret += days[i];
    if (i == 2 && IsLeapYear()) ret++;
  }
  ret += day;
  return ret;
}


int Date::operator-(const Date &c) const {
  int ret = 0;
  // if (!IsValid()) throw "Invalid date";
  if (*this == c) return 0;
  if (c.year > year ||
      (c.year == year && c.month > month) ||
      (c.year == year && c.month == month && c.day > day)
      ) {
    return -(c - *this);
  }
  for (int i = c.year; i < year; i++) {
    if (i == c.year) {
      ret += c.DaysFromFirstDayOfYear();
      continue;
    }
    ret += ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) ? 366 : 365;
  }
  ret += DaysFromFirstDayOfYear();
  return ret;
}

bool Date::operator<(const Date &c) const {
  return c - *this > 0;
}
bool Date::operator>(const Date &c) const {
  return c - *this < 0;
}
bool Date::operator==(const Date &c) const {
  return (c.year == year && c.month == month && c.day == day);
}

}  // namespace link

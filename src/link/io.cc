//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//

#include "io.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#define IT for (auto it = LinkedList->begin(); it; it = it->next)
using std::cin;
using std::cout;
using std::endl;
using std::setw;

namespace link {

List<Date> *IO::LinkedList;
void IO::CreateList(void) {
  LinkedList = new List<Date>();
}

void IO::CreateNodes(const int number) {
  static unsigned int seed = (unsigned) time(NULL);
  for (int i = 0; i < number; i++) {
    Date d = *new Date(
        (rand_r(&seed) % (2300 - 1900 + 1)) + 1900,
        (rand_r(&seed) % (12 - 1 + 1)) + 1,
        (rand_r(&seed) % (31 - 1 + 1)) + 1);
    LinkedList->push_front(d);
  }
}

void IO::C(void) {
  if (LinkedList == NULL) CreateList();
  CreateNodes(2000);
  cout << "创建成功" << endl;
}

void IO::O(void) {
  if (LinkedList == NULL) CreateList();
  int n;
  cout << "输出到第x项：";
  cin >> n;
  IT {
    if (n % 5 == 0) cout << endl;
    cout << setw(10) << it->data;
    if (--n == 0) break;
  }
  cout << endl;
}

void IO::D(void) {
  if (LinkedList == NULL) CreateList();
  LinkedList->pop_front();
  auto last = LinkedList->begin();
  IT {
    if (!it->data.IsValid() || it->next == NULL) {
      cout << "DELETED: " << it->data << endl;
      LinkedList->erase_after(last);
      it = last;
      continue;
    }
    last = it;
  }
}

void IO::N(void) {
  if (LinkedList == NULL) CreateList();
  int n = 0;
  IT {
    if ((it->data).IsValid()) continue;
    if (n % 5 == 0 && n > 0) cout << endl;
    cout << setw(10) << it->data;
    n++;
  }
  cout << endl << "共检测到" << n << "个不合法日期。" << endl;
}

void IO::P(void) {
  if (LinkedList == NULL) CreateList();
  int n = 0;
  IT {
    if (!it->data.IsValid()) continue;
    if (!(it->data).IsAllPrime()) continue;
    if (n % 5 == 0 && n > 0) cout << endl;
    cout << setw(10) << it->data;
    n++;
  }
  cout << endl << "共有" << n << "个节点全为素数。" << endl;
}

void IO::T(void) {
  if (LinkedList == NULL) CreateList();
  Date *date = new Date(1900, 1, 1);
  int n = 0;
  IT {
    if (!it->data.IsValid()) continue;
    if (n % 5 == 0 && n > 0) cout << endl;
    cout << setw(10) << it->data << ": " << (it->data - *date);
    n++;
  }
  cout << endl;
  delete date;
}

void IO::F(void) {
  if (LinkedList == NULL) CreateList();
  LinkedList->reverse();
  cout << "翻转成功" << endl;
}
void IO::A(void) {
  if (LinkedList == NULL) CreateList();
  std::vector<Date> data;
  IT {
    if ((it->data).IsValid()) {
      data.push_back(it->data);
    }
  };
  std::sort(data.begin(), data.end(), std::greater<Date>());
  LinkedList->clear();
  for (auto item : data) {
    LinkedList->push_front(item);
  }
}

void IO::I(void) {
#define DATE new Date(\
    time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday)
  if (LinkedList == NULL) CreateList();
  bool inserted_greater = false;
  bool inserted_less = false;
  struct tm *time_info = new tm;
  time_t raw_time = time(NULL);
  time_info = localtime_r(&raw_time, time_info);
  Date *date_for_compare = DATE;
  LinkedList->push_front(*(DATE));
  IT {
    if ((it->data).IsValid()) {
      if (!inserted_greater && it->data > *date_for_compare) {
        inserted_greater = true;
        LinkedList->insert_after(it, *(DATE));
      } else if (!inserted_less && it->data < *date_for_compare) {
        inserted_less = true;
        LinkedList->insert_after(it, *(DATE));
      } else if (it->next == NULL) {
        LinkedList->insert_after(it, *(DATE));
        break;
      }
    }
  };
  delete date_for_compare;
}

void IO::X(void) {
  if (LinkedList == NULL) CreateList();
  std::string line;
  std::ifstream file("Link.dat");
  if (file.is_open()) {
    while (getline(file, line)) {
      cout << line << '\n';
    }
  }
  file.close();
}
void IO::S(void) {
  if (LinkedList == NULL) CreateList();
  int n = 0;
  std::ofstream file;
  file.open("Link.dat");
  IT {
    if (n % 5 == 0) {
      if (n > 0) file << endl;
      file << " " << (n / 5 + 1) << ": ";
    }
    file.width(10);
    file << it->data;
    n++;
  };
  file.close();
}

}  // namespace link

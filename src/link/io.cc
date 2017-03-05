//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//

#include "io.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
/**
 * Macro for LinkedList iterator
 */
#define IT for (auto it = LinkedList->begin(); it; it = it->next)

namespace link {

std::unique_ptr<List<std::shared_ptr<Date>>> IO::LinkedList;
void IO::CreateList(void) {
  LinkedList = std::make_unique<List<std::shared_ptr<Date>>>();
}

/**
 * Create nodes
 * @param number number of nodes want to create
 */
void IO::CreateNodes(const int number) {
  auto seed = (unsigned) time(NULL);
  for (int i = 0; i < number; i++) {
    LinkedList->push_front(
        std::make_shared<Date>(
        (rand_r(&seed) % (2300 - 1900 + 1)) + 1900,
        (rand_r(&seed) % (12 - 1 + 1)) + 1,
        (rand_r(&seed) % (31 - 1 + 1)) + 1));
  }
}

/**
 * Create 2000 nodes
 */
void IO::C(void) {
  using std::cout;
  using std::endl;

  if (LinkedList == NULL) CreateList();
  CreateNodes(2000);
  cout << "创建成功" << endl;
}

/**
 * Print all nodes
 */
void IO::O(void) {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::setw;

  if (LinkedList == NULL) CreateList();
  int n;
  cout << "输出到第x项：";
  cin >> n;
  IT {
    if (n % 5 == 0) cout << endl;
    cout << setw(10) << *(it->data.get());
    if (--n == 0) break;
  }
  cout << endl;
}

/**
 * Delete some nodes
 * Includes:
 *   - Invalid nodes
 *   - first node
 *   - last node
 */
void IO::D(void) {
  using std::cout;
  using std::endl;

  if (LinkedList == NULL) CreateList();
  LinkedList->pop_front();
  auto last = LinkedList->begin();
  IT {
    if (!(*it->data.get()).IsValid()) {
      cout << "DELETED: " << *(it->data.get()) << endl;
      LinkedList->erase_after(last);
      it = last;
      continue;
    }
    last = it;
  }
}

/**
 * Print invalid nodes
 */
void IO::N(void) {
  using std::cout;
  using std::endl;
  using std::setw;

  if (LinkedList == NULL) CreateList();
  int n = 0;
  IT {
    if ((*(it->data.get())).IsValid()) continue;
    if (n % 5 == 0 && n > 0) cout << endl;
    cout << setw(10) << *(it->data.get());
    n++;
  }
  cout << endl << "共检测到" << n << "个不合法日期。" << endl;
}

/**
 * Print if nodes's y/m/d are prime numbers
 */
void IO::P(void) {
  using std::cout;
  using std::endl;
  using std::setw;

  if (LinkedList == NULL) CreateList();
  int n = 0;
  IT {
    if (!(*(it->data.get())).IsValid()) continue;
    if (!(*(it->data.get())).IsAllPrime()) continue;
    if (n % 5 == 0 && n > 0) cout << endl;
    cout << setw(10) << *(it->data.get());
    n++;
  }
  cout << endl << "共有" << n << "个节点全为素数。" << endl;
}

/**
 * Print all nodes' distance to 1900-1-1
 */
void IO::T(void) {
  using std::cout;
  using std::endl;
  using std::setw;

  if (LinkedList == NULL) CreateList();
  auto date = std::make_unique<Date>(1900, 1, 1);
  int n = 0;
  IT {
    if (!(*it->data.get()).IsValid()) continue;
    if (n % 5 == 0 && n > 0) cout << endl;
    cout << setw(10) << *(it->data.get()) << ": " << ((*it->data.get()) - *date);
    n++;
  }
  cout << endl;
}

/**
 * Reverse list
 */
void IO::F(void) {
  using std::cout;
  using std::endl;

  if (LinkedList == NULL) CreateList();
  LinkedList->reverse();
  cout << "翻转成功" << endl;
}

/**
 * Sort list
 */
void IO::A(void) {
  if (LinkedList == NULL) CreateList();
  std::vector<Date> data;
  IT {
    if ((*it->data.get()).IsValid()) {
      data.push_back(*(it->data.get()));
    }
  };
  std::sort(data.begin(), data.end(), std::greater<Date>());
  LinkedList->clear();
  for (auto item : data) {
    LinkedList->push_front(std::make_shared<Date>(item.year, item.month, item.day));
  }
  data.clear();
}

/**
 * Insert current date as node to list
 * Insert to:
 *   - First node
 *   - Last node
 *   - The first node which is later than current date
 *   - The first node which is earlier than current date
 */
void IO::I(void) {
#define DATE std::make_shared<Date>(\
    time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday)
  if (LinkedList == NULL) CreateList();
  bool inserted_greater = false;
  bool inserted_less = false;
  auto time_info = new tm();
  auto raw_time = time(NULL);
  time_info = localtime_r(&raw_time, time_info);
  auto date_for_compare = DATE;
  LinkedList->push_front(DATE);
  IT {
    if ((*it->data.get()).IsValid()) {
      if (!inserted_greater && *(it->data.get()) > *date_for_compare) {
        inserted_greater = true;
        LinkedList->insert_after(it, DATE);
      } else if (!inserted_less && *(it->data.get()) < *date_for_compare) {
        inserted_less = true;
        LinkedList->insert_after(it, DATE);
      } else if (it->next == NULL) {
        LinkedList->insert_after(it, DATE);
        break;
      }
    }
  };
  delete time_info;
}

/**
 * Read link.dat and output
 */
void IO::X(void) {
  using std::cout;
  using std::endl;

  if (LinkedList == NULL) CreateList();
  std::string line;
  std::ifstream file("Link.dat");
  if (file.is_open()) {
    while (getline(file, line)) {
      cout << line << endl;
    }
  }
  file.close();
}

/**
 * Save Link in memory to Link.dat
 */
void IO::S(void) {
  using std::endl;

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
    file << *(it->data.get());
    n++;
  };
  file.close();
}

}  // namespace link

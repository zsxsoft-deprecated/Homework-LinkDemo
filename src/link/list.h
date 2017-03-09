/*
 * Copyright 2017 zsx<zsx@zsxsoft.com>
 * Created by sx on 2/28/2017.
 * WTFPL License
 *
 * The definition & implement of class Link
 */

#ifndef LINK_LIST_H_
#define LINK_LIST_H_

#include <iterator>

namespace link {
/**
 * A Class to implement Linked List
 * Tried to imitate STL, But not yet compatible with STL.
 *
 * Functions don't have any comments, because you can understand them at a glance.
 * @tparam T
 */
template<class T>
class List {
 public:
  struct Node {
    explicit Node(const T data,
                  std::shared_ptr<Node> next = 0) : data(data), next(next) {
    }
    T data;
    std::shared_ptr<Node> next;
  };

  List() : head(0) {
  }

  ~List() {
    clear();
  }

  void clear() {
    while (!empty()) pop_front();
  }

  bool empty() {
    return !head;
  }

  void push_front(const T x) {
    auto tmp = std::make_shared<Node>(x, head);
    head = tmp;
  }

  void pop_front() {
    if (head) {
      auto tmp = head;
      head = head->next;
    }
  }

  void insert_after(std::shared_ptr<Node> x, const T &data) {
    auto tmp = std::make_shared<Node>(data, x->next);
    x->next = tmp;
  }

  void erase_after(std::shared_ptr<Node> x) {
    auto tmp = x->next;
    if (tmp) {
      x->next = x->next->next;
    }
  }

  T &front() {
    return head->data;
  }

  std::shared_ptr<Node> begin() {
    return head;
  }

  std::shared_ptr<Node> end() {
    return NULL;
  }

  const T &front() const {
    return head->data;
  }

  const std::shared_ptr<Node> begin() const {
    return head;
  }

  const std::shared_ptr<Node> end() const {
    return NULL;
  }

  void reverse() {
    std::shared_ptr<Node> backup = NULL;
    std::shared_ptr<Node> next;
    auto current = begin();
    while (current) {
      next = current->next;
      current->next = backup;
      backup = current;
      current = next;
    }
    head = backup;
  }

  void swap(List &x) {
    auto tmp = head;
    head = x.head;
    x.head = tmp;
  }

  List &operator=(const List &x) {
    List tmp(x);
    swap(tmp);
    return *this;
  }

 private:
  std::shared_ptr<Node> head;
};

#endif  // LINK_LIST_H_
}  // namespace link

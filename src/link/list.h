//
// Copyright 2017 zsx<zsx@zsxsoft.com>
// Created by sx on 2/28/2017.
//

#ifndef LINK_LIST_H_
#define LINK_LIST_H_
#include <iterator>
namespace link {

template<class T>
class List {
 public:
  struct Node {
    explicit Node(const T &data, Node *next = 0) : data(data), next(next) {}
    T data;
    Node *next;
  };

  List() : head(0) {}

  List(const List &L) : head(0) {
    for (const Node *i = L.begin(); i != L.end(); i = i->next)
      push_front(i->data);
    reverse();
  }

  void reverse() {
    Node *p = 0;
    Node *i = begin();
    Node *n;
    while (i) {
      n = i->next;
      i->next = p;
      p = i;
      i = n;
    }
    head = p;
  }

  void swap(List &x) {
    Node *tmp = head;
    head = x.head;
    x.head = tmp;
  }

  List &operator=(const List &x) {
    List tmp(x);
    swap(tmp);
    return *this;
  }

  ~List() { clear(); }
  void clear() { while (!empty()) pop_front(); }

  bool empty() { return !head; }

  void push_front(const T &x) {
    Node *tmp = new Node(x, head);
    head = tmp;
  }

  void pop_front() {
    if (head) {
      Node *tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  void insert_after(Node *x, const T &data) {
    Node *tmp = new Node(data, x->next);
    x->next = tmp;
  }

  void erase_after(Node *x) {
    Node *tmp = x->next;
    if (tmp) {
      x->next = x->next->next;
      delete tmp;
    }
  }

  T &front() { return head->data; }
  const T &front() const { return head->data; }

  Node *begin() { return head; }
  Node *end() { return 0; }

  const Node *begin() const { return head; }
  const Node *end() const { return 0; }

 private:
  Node *head;
};

#endif  // LINK_LIST_H_
}  // namespace link

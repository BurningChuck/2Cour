#pragma once

#include "MyList.h"
#include <string>
#include <sstream>
#include <stdexcept>

template <typename E>
struct node {
  node<E> *next;
  E value;
  node(E v) : value(v), next(NULL) {
  }
};

template <typename E>
class MyLinkedList: public MyList<E> {
private:
  node<E> *head, *tail;

public:
  MyLinkedList() : MyList<E>() {
    head = tail = NULL;
  }

  void add(E element) {
    node<E> *n = new node<E>(element);
    if (head == NULL) {
      head = tail = n;
      return;
    }
    tail->next = n;
    tail = n;
  }

  virtual E get(int index) {
    int i = 0;
    for (node<E> *t = head; t != NULL; t = t->next) {
      if (i++ == index) {
        return t->value;
      }
    }

    throw std::out_of_range("index");
  }

  E remove(int index) {
    if (head == NULL) {
      throw std::out_of_range("index");
    }

    if (index == 0) {
      node<E> *t = head;
      head = head->next;
      E ret = t->value;
      delete t;
      if (head == NULL) {
        tail = NULL;
      }
      return ret;
    }

    node<E> *prev = head;
    int i = 1;
    for (node<E> *t = prev->next; t != NULL; t = t->next) {
      if (i++ == index) {
        prev->next = t->next;
        E ret = t->value;
        delete t;
        if (prev->next == NULL) {
          tail = prev;
        }
        return ret;
      }
      prev = t;
    }

    throw std::out_of_range("index");
  }

  size_t getSize() {
    size_t ret = 0;
    for (node<E> *t = head; t != NULL; t = t->next) {
      ret++;
    }
    return ret;
  }

  int indexOf(E element) {
    int i = 0;
    for (node<E> *t = head; t != NULL; t = t->next) {
      if (t->value == element) {
        return i;
      }
      i++;
    }
    return -1;
  }

  int indexOfFirst(bool (*p)(E)) {
    int i = 0;
    for (node<E> ) {
      if (p(arr[i])) {
        return i;
      }
      i++;
    }
    return -1;
  }

  std::string toString() {
    std::stringstream ret;
    ret << "[";
    for (node<E> *t = head; t != NULL; t = t->next) {
      ret << t->value;
      if (t->next != NULL) {
        ret << ", ";
      }
    }
    ret << "]";
    return ret.str();
  }
};

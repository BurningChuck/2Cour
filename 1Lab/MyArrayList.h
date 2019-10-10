#pragma once

#include "MyList.h"
#include <string>
#include <sstream>
#include <stdexcept>

template <typename E>
class MyArrayList: public MyList<E> {
private:
  E *arr;
  size_t capacity;
  size_t size;

  void grow() {
    size_t newCap = capacity + 16;
    E *newArr = new E[newCap];
    if (arr != NULL) {
      for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
      }
      delete arr;
    }
    capacity = newCap;
    arr = newArr;
  }

public:
  MyArrayList() : MyList<E>() {
    arr = NULL;
    size = capacity = 0;
    grow();
  }

  void add(E element) {
    if (size == capacity) grow();
    arr[size++] = element;
  }

  E get(int index) {
    if (index < 0 || index >= size) {
      throw std::out_of_range("index");
    }
    return arr[index];
  }

  E remove(int index) {
    if (index < 0 || index >= size) {
      throw std::out_of_range("index");
    }
    E ret = arr[index];
    size--;
    for (int i = 0; i < (size - index); i++) {
      arr[index + i] = arr[index + i + 1];
    }
    return ret;
  }

  size_t getSize() {
    return size;
  }

  int indexOf(E element) {
    for (int i = 0; i < size; i++) {
      if (arr[i] == element) {
        return i;
      }
    }
    return -1;
  }

  int indexOfFirst(bool (*p)(E)) {
    for (int i = 0; i < size; i++) {
      if (p(arr[i])) {
        return i;
      }
    }
    return -1;
  }

  std::string toString() {
    std::stringstream ret;
    ret << "[";
    for (int i = 0; i < size; i++) {
      ret << arr[i];
      if (i != size - 1) {
        ret << ", ";
      }
    }
    ret << "]";
    return ret.str();
  }
};
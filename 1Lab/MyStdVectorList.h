#pragma once

#include "MyList.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>

template <typename E>
class MyStdVectorList: public MyList<E> {
private:
  std::vector<E> arr;

public:
  MyStdVectorList() : MyList<E>() {
  }

  void add(E element) {
    arr.push_back(element);
  }

  E get(int index) {
    return arr[index];
  }

  E remove(int index) {
    E ret = arr[index];
    arr.erase(arr.begin() + index);
    return ret;
  }

  size_t getSize() {
    return arr.size();
  }

  int indexOf(E element) {
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == element) {
        return i;
      }
    }
    return -1;
  }

  std::string toString() {
    std::stringstream ret;
    ret << "[";
    for (int i = 0; i < arr.size(); i++) {
      ret << arr[i];
      if (i != arr.size() - 1) {
        ret << ", ";
      }
    }
    ret << "]";
    return ret.str();
  }
};

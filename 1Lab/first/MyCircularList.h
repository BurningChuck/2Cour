#pragma once

#include "MyList.h"
#include <string>

template <typename E>
class MyCircularList: public MyList<E> {
private:
  MyList<E> *myList;
  int current;

public:
  MyCircularList(MyList<E> *t) : MyList<E>() {
    myList = t;
    current = 0;
  }

  E next() {
    return myList->get(current++ % myList->getSize());
  }

  void add(E element)    {        myList->add(element);     }
  E get(int index)       { return myList->get(index);       }
  E remove(int index)    { return myList->remove(index);    }
  size_t getSize()       { return myList->getSize();        }
  int indexOf(E element) { return myList->indexOf(element); }
  std::string toString() { return myList->toString();       }

  int indexOfFirst(bool (*p)(E)) {
    return myList->indexOfFirst(p);
  }
};

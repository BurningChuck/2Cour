#pragma once

#include <string>

template <typename E>
class MyList {
public:
  virtual void add(E element)     = 0;
  virtual E get(int index)        = 0;
  virtual E remove(int index)     = 0;
  virtual size_t getSize()        = 0;
  virtual int indexOf(E element)  = 0;
  virtual std::string toString()  = 0;

  virtual int indexOfFirst(bool (*p)(E)) = 0;
};

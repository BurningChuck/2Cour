#include <iostream>

#include "MyList.h"
#include "MyLinkedList.h"
#include "MyArrayList.h"
#include "MyStdVectorList.h"
#include "MyCircularList.h"

using namespace std;

int main() {
  cout << "hello world" << endl;

  MyList<string> *myList;
  
  myList = new MyLinkedList<string>;
  myList->add("hello");
  myList->add("world");
  cout << myList->toString() << endl;

  cout << endl;

  myList = new MyArrayList<string>;
  myList->add("foo");
  myList->add("bar");
  myList->add("baz");
  cout << myList->toString() << endl;

  cout << endl;

  myList = new MyStdVectorList<string>;
  myList->add("qwe");
  myList->add("asd");
  myList->add("zxc");
  cout << myList->toString() << endl;

  cout << endl;

  MyCircularList<string> *myCircularList =
    new MyCircularList<string>(myList);
  cout << "myCircularList" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "  .next() = " << myCircularList->next() << endl;
  }

  return 0;
}

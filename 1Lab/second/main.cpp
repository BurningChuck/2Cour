#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Triangle.h"
#include "Quadrangle.h"
#include "Pentagon.h"

using namespace std;

int main() {
  cout << "hello world" << endl;

  srand(time(NULL));

  Triangle tr(0, 4, 3, 5, 6, 4);
  cout << "Triangle" << tr.toString() << endl;
  cout << "  .area(): ";
  cout << tr.area() << endl;
  cout << "  .perimeter(): ";
  cout << tr.perimeter() << endl;
  cout << "  .isRightTriangle(): ";
  cout << tr.isRightTriangle() << endl;
  cout << "  .isIsosceles(): ";
  cout << tr.isIsosceles() << endl;
  cout << "  .isEquilateral(): ";
  cout << tr.isEquilateral() << endl;

  cout << endl;

  Quadrangle qd(0, 0, 0, 4, 6, 4, 6, 0);
  cout << "Quadrangle" << qd.toString() << endl;
  cout << "  .area(): ";
  cout << qd.area() << endl;
  cout << "  .perimeter(): ";
  cout << qd.perimeter() << endl;
  cout << "  .isTrapeze(): ";
  cout << qd.isTrapeze() << endl;
  cout << "  .isParallelogram(): ";
  cout << qd.isParallelogram() << endl;
  cout << "  .isRhombus(): ";
  cout << qd.isRhombus() << endl;
  cout << "  .isRectangle(): ";
  cout << qd.isRectangle() << endl;
  cout << "  .isSquare(): ";
  cout << qd.isSquare() << endl;

  cout << endl;

  Pentagon pt(0, 0, 0, 4, 3, 5, 6, 4, 6, 0);
  cout << "Pentagon" << pt.toString() << endl;
  cout << "  .area(): ";
  cout << pt.area() << endl;
  cout << "  .perimeter(): ";
  cout << pt.perimeter() << endl;
  cout << "  .isRegularPentagon(): ";
  cout << pt.isRegularPentagon() << endl;

  cout << endl;

  Pentagon pt2 = Pentagon::random();
  cout << "random Pentagon" << pt2.toString() << endl;
  cout << "  .area(): ";
  cout << pt2.area() << endl;
  cout << "  .perimeter(): ";
  cout << pt2.perimeter() << endl;
  cout << "  .isRegularPentagon(): ";
  cout << pt2.isRegularPentagon() << endl;

  return 0;
}

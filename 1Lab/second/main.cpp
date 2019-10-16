#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Triangle.h"
#include "Quadrangle.h"
#include "Pentagon.h"

using namespace std;

int main() {
  cout << "hello world" << endl;

  // чтобы правильно работал рандом
  srand(time(NULL));

  // создаём треугольник
  Triangle tr(0, 4, 3, 5, 6, 4);
  cout << "Triangle" << tr.toString() << endl;
  // выводим его площадь
  cout << "  .area(): ";
  cout << tr.area() << endl;
  // периметр
  cout << "  .perimeter(): ";
  cout << tr.perimeter() << endl;
  // проверяем является ли он прямоугольным
  cout << "  .isRightTriangle(): ";
  cout << tr.isRightTriangle() << endl;
  // равнобедренным
  cout << "  .isIsosceles(): ";
  cout << tr.isIsosceles() << endl;
  // равносторонним
  cout << "  .isEquilateral(): ";
  cout << tr.isEquilateral() << endl;

  cout << endl;

  // создаём четырёхугольник
  Quadrangle qd(0, 0, 0, 4, 6, 4, 6, 0);
  cout << "Quadrangle" << qd.toString() << endl;
  // выводим его площадь
  cout << "  .area(): ";
  cout << qd.area() << endl;
  // периметр
  cout << "  .perimeter(): ";
  cout << qd.perimeter() << endl;
  // проверяем является ли он трапецией
  cout << "  .isTrapeze(): ";
  cout << qd.isTrapeze() << endl;
  // параллелограммом
  cout << "  .isParallelogram(): ";
  cout << qd.isParallelogram() << endl;
  // ромбом
  cout << "  .isRhombus(): ";
  cout << qd.isRhombus() << endl;
  // прямоугольником
  cout << "  .isRectangle(): ";
  cout << qd.isRectangle() << endl;
  // квадратом
  cout << "  .isSquare(): ";
  cout << qd.isSquare() << endl;

  cout << endl;

  // создаём пятиугольник
  Pentagon pt(0, 0, 0, 4, 3, 5, 6, 4, 6, 0);
  cout << "Pentagon" << pt.toString() << endl;
  // выводим его площадь
  cout << "  .area(): ";
  cout << pt.area() << endl;
  // периметр
  cout << "  .perimeter(): ";
  cout << pt.perimeter() << endl;
  // проверяем является ли он правильным
  cout << "  .isRegularPentagon(): ";
  cout << pt.isRegularPentagon() << endl;

  cout << endl;

  // создаём пятиугольник со случайными точками
  Pentagon pt2 = Pentagon::random();
  cout << "random Pentagon" << pt2.toString() << endl;
  // выводим его площадь
  cout << "  .area(): ";
  cout << pt2.area() << endl;
  // периметр
  cout << "  .perimeter(): ";
  cout << pt2.perimeter() << endl;
  // проверяем является ли он правильным
  cout << "  .isRegularPentagon(): ";
  cout << pt2.isRegularPentagon() << endl;

  return 0;
}

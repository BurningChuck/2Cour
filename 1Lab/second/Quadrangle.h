#pragma once

#include "Shape.h"
#include <cmath>

// класс четырёхугольника
//   наследуемся от родительского класса Shape с 4 углами/рёбрами
class Quadrangle: public Shape<4> {
private:
  // статический метод для проверки параллельности прямых
  //   (каждая задаётся двумя точками)
  static bool areParallel(
    double xA1, double yA1,
    double xA2, double yA2,
    double xB1, double yB1,
    double xB2, double yB2
  ) {
    double u = (yA2 - yA1) * (xB2 - xB1);
    double v = (yB2 - yB1) * (xA2 - xA1);
    return fabs(u - v) < 0.001;
  }

  // статический метод для проверки перпендикулярности прямых
  //   (каждая задаётся двумя точками)
  static bool arePerpendicular(
    double xA1, double yA1,
    double xA2, double yA2,
    double xB1, double yB1,
    double xB2, double yB2
  ) {
    double u = (xA2 - xA1) * (xB2 - xB1);
    double v = (yA2 - yA1) * (yB2 - yB1);
    return fabs(u + v) < 0.001;
  }

public:
  // статический метод для создания четырёхугольника со случайными точками
  static Quadrangle random() {
     return Quadrangle(
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100
     );
  }

  // конструктор по 4ём точкам
  Quadrangle(
    double x1, double y1,
    double x2, double y2,
    double x3, double y3,
    double x4, double y4
  ) : Shape() {
    // заносим их в массив точек в родительском классе
    vertices[0][0] = x1;
    vertices[0][1] = y1;
    vertices[1][0] = x2;
    vertices[1][1] = y2;
    vertices[2][0] = x3;
    vertices[2][1] = y3;
    vertices[3][0] = x4;
    vertices[3][1] = y4;
  }

  // является ли четырёхугольник трапецией
  bool isTrapeze() {
    // проверяем есть ли пара параллельных противоположных сторон
    for (int i = 0; i < 2; i++) {
      if (
        areParallel(
          vertices[ i + 0     ][0], vertices[ i + 0     ][1],
          vertices[ i + 1     ][0], vertices[ i + 1     ][1],
          vertices[ i + 2     ][0], vertices[ i + 2     ][1],
          vertices[(i + 3) % 4][0], vertices[(i + 3) % 4][1]
        )
      ) return true;
    }
    return false;
  }

  // является ли четырёхугольник параллелограммом
  bool isParallelogram() {
    // проверяем параллельны ли все попарно противоположные стороны
    for (int i = 0; i < 2; i++) {
      if (
        !areParallel(
          vertices[ i + 0     ][0], vertices[ i + 0     ][1],
          vertices[ i + 1     ][0], vertices[ i + 1     ][1],
          vertices[ i + 2     ][0], vertices[ i + 2     ][1],
          vertices[(i + 3) % 4][0], vertices[(i + 3) % 4][1]
        )
      ) return false;
    }
    return true;
  }

  // является ли четырёхугольник прямоугольником
  bool isRectangle() {
    // проверяем перпендикулярны ли все попарно противоположные стороны
    for (int i = 0; i < 2; i++) {
      if (
        !arePerpendicular(
          vertices[ i + 0     ][0], vertices[ i + 0     ][1],
          vertices[ i + 1     ][0], vertices[ i + 1     ][1],
          vertices[ i + 2     ][0], vertices[ i + 2     ][1],
          vertices[(i + 3) % 4][0], vertices[(i + 3) % 4][1]
        )
      ) return false;
    }
    return true;
  }

  // является ли четырёхугольник ромбом
  bool isRhombus() {
    // все стороны одной длины и параллелограмм
    return isHalfRegular() && isParallelogram();
  }

  // является ли четырёхугольник квадратом
  bool isSquare() {
    // все стороны одной длины и прямоугольник
    return isHalfRegular() && isRectangle();
  }
};

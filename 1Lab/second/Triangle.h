#pragma once

#include "Shape.h"
#include <cmath>

// класс треугольника
//   наследуемся от родительского класса Shape с 3 углами/рёбрами
class Triangle: public Shape<3> {
public:
  // статический метод для создания треугольника со случайными точками
  static Triangle random() {
     return Triangle(
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100
     );
  }

  // конструктор по 3ём точкам
  Triangle(
    double x1, double y1,
    double x2, double y2,
    double x3, double y3
  ) : Shape() {
    // заносим их в массив точек в родительском классе
    vertices[0][0] = x1;
    vertices[0][1] = y1;
    vertices[1][0] = x2;
    vertices[1][1] = y2;
    vertices[2][0] = x3;
    vertices[2][1] = y3;
  }

  // является ли треугольник прямоугольным
  bool isRightTriangle() {
    double e[3];
    // получаем стороны
    edges(e);
    // для каждой стороны
    for (int i = 0; i < 3; i++) {
      // проверяем C^2 = A^2 + B^2
      double t =
        e[(i + 1) % 3] * e[(i + 1) % 3] +
        e[(i + 2) % 3] * e[(i + 2) % 3] -
        e[ i         ] * e[ i         ];
      if (fabs(t) < 0.001) {
        return true;
      }
    }
    return false;
  }

  // является ли треугольник равнобедренным
  bool isIsosceles() {
    double e[3];
    // получаем стороны
    edges(e);
    // проверяем есть ли пара сторон A = B
    for (int i = 0; i < 3; i++) {
      double t = e[(i + 1) % 3] - e[i];
      if (fabs(t) < 0.001) {
        return true;
      }
    }
    return false;
  }

  // является ли треугольник равносторонним
  bool isEquilateral() {
    // все стороны равны
    return isHalfRegular();
  }
};

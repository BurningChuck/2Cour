#pragma once

#include "Shape.h"
#include <cstdlib>

// класс пятиугольника
//   наследуемся от родительского класса Shape с 5 углами/рёбрами
class Pentagon: public Shape<5> {
public:
  // статический метод для создания пятиугольника со случайными точками
  static Pentagon random() {
     return Pentagon(
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100
     );
  }

  // конструктор по 5ти точкам
  Pentagon(
    double x1, double y1,
    double x2, double y2,
    double x3, double y3,
    double x4, double y4,
    double x5, double y5
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
    vertices[4][0] = x5;
    vertices[4][1] = y5;
  }

  // является ли пятиугольник правильным
  bool isRegularPentagon() {
    // если стороны не одной длины - сразу нет
    if (!isHalfRegular()) return false;

    // считаем диагональ из первой точки
    double dx = vertices[(1 + 2) % 5][0] - vertices[1][0];
    double dy = vertices[(1 + 2) % 5][1] - vertices[1][1];
    double diagonal = sqrt(dx * dx + dy * dy);

    // для каждой следующей точки
    for (int i = 1; i < 5; i++) {
      // считаем диагональ
      dx = vertices[(i + 2) % 5][0] - vertices[i][0];
      dy = vertices[(i + 2) % 5][1] - vertices[i][1];
      // если её длина отличается от первой
      if (fabs(sqrt(dx * dx + dy * dy) - diagonal) < 0.001) {
        // то пятиугольник не является правильным
        return false;
      }
    }

    return true;
  }
};

#pragma once

#include <string>
#include <sstream>
#include <cmath>

// общий родительский класс для всех фигур
//   N - кол-во углов/рёбер
template <int N>
class Shape {
protected:
  // двумерный массив точек в виде
  //   [[x1, y1], [x2, y2], ..., [xN, yN]]
  double vertices[N][2];

  // метод для получения длин всех рёбер
  void edges(double ret[N]) {
    // проходим по каждой точке
    for (int i = 0; i < N; i++) {
      // считаем разницу координат i-ой и (i+1)-ой точек
      //   (берём по модулю чтобы последняя (i+1)-ая точка была 0)
      double dx = vertices[(i + 1) % N][0] - vertices[i][0];
      double dy = vertices[(i + 1) % N][1] - vertices[i][1];
      // считаем корень и записываем результат в выходной массив
      ret[i] = sqrt(dx * dx + dy * dy);
    }
  }

  // метод для проверки являются ли все рёбра одинаковыми
  bool isHalfRegular() {
    double e[N];
    edges(e);
    for (int i = 1; i < N; i++) {
      if (fabs(e[i] - e[0]) > 0.001) {
        return false;
      }
    }
    return true;
  }

public:
  // периметр
  double perimeter() {
    double ret = 0.0, e[N];
    // получаем рёбра
    edges(e);
    // суммируем
    for (int i = 0; i < N; i++) {
      ret += e[i];
    }
    // возвращаем результат
    return ret;
  }

  // площадь по формуле
  //   https://en.wikipedia.org/wiki/Shoelace_formula
  double area() {
    double ret = 0.0;
    for (int i = 0; i < N; i++) {
      ret += vertices[i][0] * vertices[(i + 1) % N][1];
      ret -= vertices[(i + 1) % N][0] * vertices[i][1];
    }
    return 0.5 * fabs(ret);
  }

  // метод для получения строкового представления фигуры по точкам
  std::string toString() {
    std::stringstream ret;
    ret << "(";
    for (int i = 0; i < N; i++) {
      ret << "(" << vertices[i][0] << ", " << vertices[i][1] << ")";
      if (i != N - 1) ret << ", ";
    }
    ret << ")";
    return ret.str();
  }
};

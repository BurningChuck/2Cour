#pragma once

#include "Shape.h"
#include <cmath>

class Triangle: public Shape<3> {
public:
  static Triangle random() {
     return Triangle(
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100
     );
  }

  Triangle(
    double x1, double y1,
    double x2, double y2,
    double x3, double y3
  ) : Shape() {
    vertices[0][0] = x1;
    vertices[0][1] = y1;
    vertices[1][0] = x2;
    vertices[1][1] = y2;
    vertices[2][0] = x3;
    vertices[2][1] = y3;
  }

  bool isRightTriangle() {
    double e[3];
    edges(e);
    for (int i = 0; i < 3; i++) {
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

  bool isIsosceles() {
    double e[3];
    edges(e);
    for (int i = 0; i < 3; i++) {
      double t = e[(i + 1) % 3] - e[i];
      if (fabs(t) < 0.001) {
        return true;
      }
    }
    return false;
  }

  bool isEquilateral() {
    return isHalfRegular();
  }
};

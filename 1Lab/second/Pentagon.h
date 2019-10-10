#pragma once

#include "Shape.h"
#include <cstdlib>

class Pentagon: public Shape<5> {
public:
  static Pentagon random() {
     return Pentagon(
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100,
       rand() % 100, rand() % 100
     );
  }

  Pentagon(
    double x1, double y1,
    double x2, double y2,
    double x3, double y3,
    double x4, double y4,
    double x5, double y5
  ) : Shape() {
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

  bool isRegularPentagon() {
    if (!isHalfRegular()) return false;

    double dx = vertices[(1 + 2) % 5][0] - vertices[1][0];
    double dy = vertices[(1 + 2) % 5][1] - vertices[1][1];
    double diagonal = sqrt(dx * dx + dy * dy);

    for (int i = 1; i < 5; i++) {
      dx = vertices[(i + 2) % 5][0] - vertices[i][0];
      dy = vertices[(i + 2) % 5][1] - vertices[i][1];
      if (fabs(sqrt(dx * dx + dy * dy) - diagonal) < 0.001) {
        return false;
      }
    }

    return true;
  }
};

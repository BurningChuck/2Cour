#pragma once

#include <string>
#include <sstream>
#include <cmath>

template <int N>
class Shape {
protected:
  double vertices[N][2];

  void edges(double ret[N]) {
    for (int i = 0; i < N; i++) {
      double dx = vertices[(i + 1) % N][0] - vertices[i][0];
      double dy = vertices[(i + 1) % N][1] - vertices[i][1];
      ret[i] = sqrt(dx * dx + dy * dy);
    }
  }

public:
  double perimeter() {
    double ret = 0.0, e[N];
    edges(e);
    for (int i = 0; i < N; i++) {
      ret += e[i];
    }
    return ret;
  }

  // https://en.wikipedia.org/wiki/Shoelace_formula
  double area() {
    double ret = 0.0;
    for (int i = 0; i < N; i++) {
      ret += vertices[i][0] * vertices[(i + 1) % N][1];
      ret -= vertices[(i + 1) % N][0] * vertices[i][1];
    }
    return 0.5 * fabs(ret);
  }

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

#include <iostream>
#include <vector>
#include "circle.h"
#include "ishape.h"
#include "line.h"
#include "point.h"
#include "polygon.h"
#include "ray.h"
#include "segment.h"
#include "vector.h"

int main() {
  std::vector<geometry::IShape> shapes;
  std::string str_1, str_2;
  int n, a, b, c, d;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> str_1;    //тип команды
    if (str_1 == "new") {
      std::cin >> str_2;    //тип фигуры
      if (str_2 == "circle") {
        std::cin >> a >> b >> c;    //к-ты центра и радиус
      } else if (str_2 == "line") {
        std::cin >> a >> b >> c >> d;   //к-ты двух точек линии
      } else if (str_2 == "point") {
        std::cin >> a >> b;   //к-ты точки
      } else if (str_2 == "ray") {
        std::cin >> a >> b >> c >> d;   //к-ты точки начала и вектора направления
      } else if (str_2 == "segment") {
        std::cin >> a >> b >> c >> d;   //к-ты двух концов
      } else if (str_2 == "vector") {
        std::cin >> a >> b;   //компоненты вектора
        shapes[i] = geometry::Vector(a, b);
      } else if (str_2 == "polygon") {
        std::cin >> a;    //число вершин
        std::vector<geometry::Point> oth;
        for (int j = 0; j < a; ++j) {
          std::cin >> b >> c;   //к-ты вершины
          oth.emplace_back(b, c);   //вставка вершины
        }
        shapes[i] = geometry::Polygon(oth);
      }
    }
  }
  return 0;
}

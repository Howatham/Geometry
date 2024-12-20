#include <iostream>
#include "../polygon.h"
#include "../point.h"
#include "../segment.h"

geometry::Polygon& geometry::Polygon::Move(const geometry::Vector& oth) {
  for (Point& i : points) {
    i.x += oth.x;
    i.y += oth.y;
  }
  return *this;
}
bool geometry::Polygon::ContainsPoint(const geometry::Point& oth) const {
  bool flag_point = false;
  int64_t p_size = points.size();
  for (int i = 0; i < p_size; ++i) {
    if (Segment(points[i], points[(i + 1) % p_size]).ContainsPoint(oth)) {  //проверка на вершину
      flag_point = true;
    }
  }
  if (flag_point) {
    return true;
  }
  int64_t inters = 0;
  Segment a = Segment(oth, Point(oth.x + 20001, oth.y + 1));
  for (int i = 0; i < p_size; ++i) {
    if (a.CrossesSegment(Segment(points[i], points[(i + 1) % p_size]))) {
      ++inters;
    }
  }
  return (inters % 2 != 0);
}
bool geometry::Polygon::CrossesSegment(const geometry::Segment& oth) const {
  int64_t p_size = points.size();
  for (int i = 0; i < p_size; ++i) {
    if (oth.CrossesSegment(Segment(points[i], points[(i + 1) % p_size]))) {
      return true;
    }
  }
  return false;
}
std::unique_ptr<geometry::IShape> geometry::Polygon::Clone() const {
  return std::make_unique<Polygon>(points);
}
std::string geometry::Polygon::ToString() const {
  std::string ret = std::string();
  ret += "Polygon(";
  int64_t p_size = points.size();
  for (int i = 0; i < p_size - 1; ++i) {
    ret += points[i].ToString();
    ret += ", ";
  }
  ret += points[p_size - 1].ToString();
  ret += ")";
  return ret;
}
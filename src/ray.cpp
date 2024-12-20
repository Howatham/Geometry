#include <iostream>
#include "../ray.h"
#include "../line.h"

geometry::Ray::Ray() : p(Point(0, 0)), v(Vector(1, 0)) {
}
geometry::Ray::Ray(const Point& a, const Point& b) : p(a), v(b - a) {
}

geometry::Ray& geometry::Ray::Move(const Vector& a) {
  this->p.x += a.x;
  this->p.y += a.y;
  return *this;
}
bool geometry::Ray::ContainsPoint(const geometry::Point& a) const {
  if (this->p.ContainsPoint(a)) {
    return true;
  }
  Vector tmp = a - this->p;
  return (Collinear(tmp, this->v) == 1);
}
bool geometry::Ray::CrossesSegment(const geometry::Segment& oth) const {
  if (oth.a.x == oth.b.x && oth.a.y == oth.b.y) {
    return this->ContainsPoint(oth.a);
  }
  if (oth.ContainsPoint(p)) {
    return true;
  }
  if (!(geometry::Line(p, Point(p.x + v.x, p.y + v.y))).CrossesSegment(oth)) {
    return false;
  }
  if (Collinear(this->v, oth.b - oth.a)) {  //параллельность, при коллинеарном возвращается +-1, приводится к true
    return ((this->ContainsPoint(oth.a) || this->ContainsPoint(oth.b)));
  }
  Vector po = p - oth.a;
  Vector pq = oth.b - oth.a;
  return (((po ^ pq) * (v ^ pq) < 0) || ((po ^ pq) == 0));
}
std::unique_ptr<geometry::IShape> geometry::Ray::Clone() const {
  return std::make_unique<Ray>(this->p, Point(this->p.x + v.x, p.y + v.y));
}
std::string geometry::Ray::ToString() const {
  std::string ret = "Ray(Point(";
  ret += std::to_string(p.x);
  ret += ", ";
  ret += std::to_string(p.y);
  ret += "), Vector(";
  ret += std::to_string(v.x);
  ret += ", ";
  ret += std::to_string(v.y);
  ret += "))";  // ret = ret + p.x + ", " + p.y + "), Vector(" + v.x + ", " + v.y + "))";
  return ret;
}

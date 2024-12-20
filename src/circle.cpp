#include "../circle.h"
#include "../segment.h"
#include "../line.h"

geometry::Circle::Circle(const Point& po, int ra) : p(po), r(ra) {
}
geometry::Circle& geometry::Circle::Move(const geometry::Vector& oth) {
  this->p.x += oth.x;
  this->p.y += oth.y;
  return *this;
}
bool geometry::Circle::ContainsPoint(const geometry::Point& oth) const {
  int64_t xr = oth.x - this->p.x;
  int64_t yr = oth.y - this->p.y;
  return (((xr * xr) + (yr * yr)) <= r * r);
}
bool geometry::Circle::CrossesSegment(const geometry::Segment& oth) const {
  if (oth.a.x == oth.b.x && oth.a.y == oth.b.y) {  // если отрезок вырожден
    return ((oth.a.x - this->p.x) * (oth.a.x - this->p.x) + (oth.a.y - this->p.y) * (oth.a.y - this->p.y) == r * r);
  }
  if (((oth.a.x - this->p.x) * (oth.a.x - this->p.x) + (oth.a.y - this->p.y) * (oth.a.y - this->p.y) == r * r) ||
      ((oth.b.x - this->p.x) * (oth.b.x - this->p.x) + (oth.b.y - this->p.y) * (oth.b.y - this->p.y) ==
       r * r)) {  // если хоть один конец ровно на окружности
    return true;
  }
  if ((this->ContainsPoint(oth.a) && this->ContainsPoint(oth.b))) {  // если оба конца в окружности
    return false;
  }
  if ((this->ContainsPoint(oth.a) && !this->ContainsPoint(oth.b)) ||
      (!this->ContainsPoint(oth.a) && this->ContainsPoint(oth.b))) {  // один конец внутри, другой снаружи
    return true;
  }
  Line tmp = Line(oth.a, oth.b);
  if ((tmp.a * p.x + tmp.b * p.y + tmp.c) *
          (tmp.a * p.x + tmp.b * p.y + tmp.c)  // линия на нашем отрезке хотя бы касается окружности
      <= r * r * (tmp.a * tmp.a + tmp.b * tmp.b)) {
    Line orth = Line(p, Point(p.x + tmp.a, p.y + tmp.b));  // линия, перпендикулярная линии на нашем отрезке
    return (orth.CrossesSegment(oth));
  }
  return false;
}
std::unique_ptr<geometry::IShape> geometry::Circle::Clone() const {
  return std::make_unique<Circle>(p, r);
}
std::string geometry::Circle::ToString() const {
  std::string ret = std::string();
  ret += "Circle(Point(";
  ret += std::to_string(p.x);
  ret += ", ";
  ret += std::to_string(p.y);
  ret += "), ";
  ret += std::to_string(r);
  ret += ")";
  return ret;
}
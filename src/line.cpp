#include "../line.h"
#include "../point.h"
#include "../segment.h"

geometry::Line::Line() : a(1), b(0), c(0), p(geometry::Point(0, 0)), v(geometry::Vector(0, 1)) {
}
geometry::Line::Line(const Point& f, const Point& s)
    : a(-(s - f).y), b((s - f).x), c(-a * f.x - b * f.y), p(f), v(s - f) {
}

geometry::Line& geometry::Line::Move(const geometry::Vector& oth) {
  Point tmp = p.Move(oth);
  *this = Line(tmp, Point(tmp.x + v.x, tmp.y + v.y));
  return *this;
}
bool geometry::Line::ContainsPoint(const geometry::Point& oth) const {
  return ((a * oth.x + b * oth.y + c) == 0);
}
std::unique_ptr<geometry::IShape> geometry::Line::Clone() const {
  return std::make_unique<Line>(p, Point(p.x + v.x, p.y + v.y));
}
bool geometry::Line::CrossesSegment(const geometry::Segment& oth) const {
  if (this->ContainsPoint(oth.a) || this->ContainsPoint(oth.b)) {
    return true;
  }
  return (((a * oth.a.x + b * oth.a.y + c) * (a * oth.b.x + b * oth.b.y + c)) <= 0);
}
std::string geometry::Line::ToString() const {
  std::string ret = std::string();
  ret += "Line(";
  ret += std::to_string(a);
  ret += ", ";
  ret += std::to_string(b);
  ret += ", ";
  ret += std::to_string(c);
  ret += ")";
  return ret;
}

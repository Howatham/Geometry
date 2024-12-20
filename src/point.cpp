#include "../point.h"
#include "../segment.h"

geometry::Point::Point() : x(0), y(0) {
}
geometry::Point::Point(int64_t x, int64_t y) : x(x), y(y) {
}

geometry::Point& geometry::Point::Move(const Vector& a) {
  x += a.x;
  y += a.y;
  return *this;
}
bool geometry::Point::ContainsPoint(const geometry::Point& a) const {
  return (x == a.x && y == a.y);
}
bool geometry::Point::CrossesSegment(const geometry::Segment& oth) const {
  if (oth.a.x == oth.b.x && oth.a.y == oth.b.y) {
    return this->ContainsPoint(oth.a);
  }
  Vector ac = *this - oth.a;
  Vector ab = *this - oth.b;
  return ((Collinear(ac, ab) == -1));
}
std::unique_ptr<geometry::IShape> geometry::Point::Clone() const {
  return std::make_unique<Point>(this->x, this->y);
}
std::string geometry::Point::ToString() const {  // Point(2, 2)
  std::string ret = std::string();
  ret += "Point(";
  ret += std::to_string(x);
  ret += ", ";
  ret += std::to_string(y);
  ret += ")";
  return ret;
}
geometry::Vector geometry::operator-(const geometry::Point& first, const geometry::Point& sec) {
  return {first.x - sec.x, first.y - sec.y};
}

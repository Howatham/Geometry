#include "../segment.h"
#include "../ray.h"

geometry::Segment::Segment(const geometry::Point& a, const geometry::Point& b) : a(a), b(b) {
}

geometry::Segment& geometry::Segment::Move(const Vector& oth) {
  a.x += oth.x;
  a.y += oth.y;
  b.x += oth.x;
  b.y += oth.y;
  return *this;
}
bool geometry::Segment::ContainsPoint(const geometry::Point& oth) const {
  return oth.CrossesSegment(*this);
}
bool geometry::Segment::CrossesSegment(const geometry::Segment& oth) const {
  if (oth.a.x == oth.b.x && oth.a.y == oth.b.y) {
    return this->ContainsPoint(oth.a);
  }
  if (this->a.x == this->b.x && this->a.y == this->b.y) {
    return oth.ContainsPoint(this->a);
  }
  Ray f = Ray(oth.a, oth.b);
  Ray s = Ray(oth.b, oth.a);
  return (f.CrossesSegment(*this) && s.CrossesSegment(*this));
}

std::unique_ptr<geometry::IShape> geometry::Segment::Clone() const {
  return std::make_unique<Segment>(a, b);
}
std::string geometry::Segment::ToString() const {
  std::string ret = std::string();
  ret += "Segment(";
  ret += a.ToString();
  ret += ", ";
  ret += b.ToString();
  ret += ")";
  return ret;
}
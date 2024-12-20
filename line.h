#pragma once
#include "ishape.h"
#include "vector.h"
#include "point.h"

namespace geometry {

class Vector;
class Point;
class Segment;

class Line : public IShape {
 public:
  int64_t a;
  int64_t b;
  int64_t c;
  Point p;
  Vector v;

 public:
  Line();
  Line(const Point& a, const Point& b);

  Line& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};

}  // namespace geometry
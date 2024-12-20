#pragma once
#include "ishape.h"
#include "point.h"

namespace geometry {

class Vector;
class Point;

class Segment : public IShape {
 public:
  Point a;
  Point b;

  Segment(const Point& a, const Point& b);

  Segment& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};

}  // namespace geometry
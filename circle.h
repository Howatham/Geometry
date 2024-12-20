#pragma once
#include "ishape.h"
#include "vector.h"
#include "point.h"

namespace geometry {

class Vector;
class Point;
class Segment;

class Circle : public IShape {
 public:
  Point p;
  int64_t r;

  Circle() = default;
  Circle(const Point&, int);

  Circle& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};

}  // namespace geometry

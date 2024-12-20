#pragma once
#include <vector>
#include "ishape.h"
#include "vector.h"

namespace geometry {

class Vector;
class Point;

class Polygon : public IShape {
 public:
  std::vector<Point> points;

  Polygon() = default;
  explicit Polygon(const std::vector<Point>& oth) : points(oth){};  // реализация в хэдере, т.к. среда возмущается

  Polygon& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};

}  // namespace geometry
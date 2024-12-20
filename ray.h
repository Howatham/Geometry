#pragma once
#include "ishape.h"
#include "vector.h"
#include "segment.h"
#include "point.h"

namespace geometry {

class Vector;
class Point;
class Segment;

class Ray : public IShape {
 public:
  Point p;
  Vector v;

  Ray();
  Ray(const Point&, const Point&);

  Ray& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};

}  // namespace geometry
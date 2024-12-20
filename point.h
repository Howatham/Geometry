#pragma once
#include "ishape.h"

namespace geometry {

class Vector;
class Segment;

class Point : public IShape {
 public:
  int64_t x;
  int64_t y;

  Point();
  Point(int64_t x, int64_t y);

  Point& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;

  friend Vector operator-(const Point& first, const Point& sec);
};

Vector operator-(const Point& first, const Point& sec);

}  // namespace geometry
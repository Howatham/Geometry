#include "../vector.h"

geometry::Vector::Vector(int64_t x, int64_t y) : x(x), y(y) {
}

geometry::Vector geometry::Vector::operator+() const {
  return Vector(x, y);
}
geometry::Vector geometry::Vector::operator-() const {
  return geometry::Vector(-x, -y);
}

geometry::Vector geometry::Vector::operator*(const int64_t a) const {
  return geometry::Vector(x * a, y * a);
}
geometry::Vector geometry::Vector::operator/(const int64_t a) const {
  return geometry::Vector(x / a, y / a);
}
geometry::Vector& geometry::Vector::operator*=(const int64_t a) {
  *this = *this * a;
  return *this;
}
geometry::Vector& geometry::Vector::operator/=(const int64_t a) {
  *this = *this / a;
  return *this;
}
bool geometry::operator==(const geometry::Vector a, const geometry::Vector b) {
  return (a.x == b.x && a.y == b.y);  // MB CRINGE
}

geometry::Vector geometry::operator+(const geometry::Vector& first, const geometry::Vector& sec) {
  return geometry::Vector(first.x + sec.x, sec.y + first.y);
}
geometry::Vector geometry::operator-(const geometry::Vector& first, const geometry::Vector& sec) {
  return geometry::Vector(first.x - sec.x, sec.y - first.y);
}

geometry::Vector& geometry::Vector::operator+=(const geometry::Vector& other) {
  *this = *this + other;
  return *this;
}
geometry::Vector& geometry::Vector::operator-=(const geometry::Vector& other) {
  *this = *this - other;
  return *this;
}
int64_t geometry::Vector::operator^(const geometry::Vector& sec) const {
  return x * sec.y - y * sec.x;
}
int geometry::Collinear(const geometry::Vector& first, const geometry::Vector& sec) {
  int64_t tmp1 = first.x * sec.y;
  int64_t tmp2 = first.y * sec.x;
  if (tmp1 == tmp2) {
    return ((first.x > 0 && sec.x > 0) || (first.y > 0 && sec.y > 0) || (first.x < 0 && sec.x < 0) ||
            (first.y < 0 && sec.y < 0))
               ? 1
               : -1;
  }
  return 0;
}

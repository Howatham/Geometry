#pragma once
#include <cstdint>
namespace geometry {

class Vector {
 public:
  int64_t x;
  int64_t y;

  Vector() : x(0), y(0) {
  }
  Vector(int64_t x, int64_t y);

  Vector operator+() const;
  Vector operator-() const;

  Vector operator*(const int64_t a) const;
  Vector operator/(const int64_t a) const;

  Vector& operator*=(const int64_t a);
  Vector& operator/=(const int64_t a);

  friend bool operator==(const Vector a, const Vector b);

  friend Vector operator+(const Vector& first, const Vector& sec);
  friend Vector operator-(const Vector& first, const Vector& sec);

  Vector& operator+=(const Vector& other);
  Vector& operator-=(const Vector& other);

  int64_t operator^(const Vector& sec) const;

  friend int Collinear(
      const Vector& first,
      const Vector& sec);  // 0, если неколл., 1, если сонапр., -1, если противонапр., верно только для ненулевых
};

bool operator==(const Vector a, const Vector b);

Vector operator+(const Vector& first, const Vector& sec);
Vector operator-(const Vector& first, const Vector& sec);
int Collinear(const Vector& first, const Vector& sec);

}  // namespace geometry
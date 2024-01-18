#pragma once

#include <cmath>
template <class T> class Vector2
{
public:
  T x;
  T y;

  Vector2(): x(0), y(0) {}
  Vector2(T x, T y): x(x), y(y) {}
  
  /**
  * @brief Normalizes the vector
  */
  void normalize()
  {
    T norm = std::sqrt(x*x + y*y);
    x = x/norm;
    y = y/norm;
  }
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

template <class T> class Vector3
{
  T x;
  T y;
  T z;

  Vector3(): x(0), y(0), z(0) {}
  Vector3(T x, T y): x(x), y(y), z(z) {}

  /**
  * @brief Normalizes the vector
  */
  void normalize()
  {
    T norm = std::sqrt(x*x + y*y + z*z);
    x = x/norm;
    y = y/norm;
    z = z/norm;
  }
};

typedef Vector3<int> Vector3i;
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;

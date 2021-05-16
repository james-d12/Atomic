#ifndef ATOMIC_GEOMETRY_TRIANGLE_HPP
#define ATOMIC_GEOMETRY_TRIANGLE_HPP

#include "atomic/linear-algebra/traits.hpp"
#include "atomic/linear-algebra/vector.hpp"

namespace atomic {
namespace geometry {

  template<typename T>
  class triangle
  {
    static_assert(linalg::is_scalar_element<T>::value, "triangle template parameter must be a scalar type!");

  public:
    constexpr triangle() = default;
    constexpr triangle(triangle &) = default;
    constexpr triangle(triangle &&) noexcept = default;
    ~triangle() = default;

    constexpr triangle(const T &a1, const T &a2, const T &b1, const T &b2, const T &c1, const T &c2);
    constexpr triangle(const linalg::fvector2<T> &_a, const linalg::fvector2<T> &_b, const linalg::fvector2<T> &_c);

    void translate(const linalg::fvector2<T> &translation);

    //returns the number of faces.
    ATOMIC_NODISCARD constexpr auto faces() const noexcept;
    //returns the number of vertices.
    ATOMIC_NODISCARD constexpr auto vertices() const noexcept;
    //returns the number of edges.
    ATOMIC_NODISCARD constexpr auto edges() const noexcept;

    //returns the length of side a.
    ATOMIC_NODISCARD constexpr auto side_a() const noexcept;
    //returns the length of side b.
    ATOMIC_NODISCARD constexpr auto side_b() const noexcept;
    //returns the length of side c.
    ATOMIC_NODISCARD constexpr auto side_c() const noexcept;

    //returns the angle of a.
    ATOMIC_NODISCARD constexpr auto angle_a() const noexcept;
    //returns the angle of b.
    ATOMIC_NODISCARD constexpr auto angle_b() const noexcept;
    //returns the angle of c.
    ATOMIC_NODISCARD constexpr auto angle_c() const noexcept;

    //returns the height of a.
    ATOMIC_NODISCARD constexpr auto height_a() const noexcept;
    //returns the height of b.
    ATOMIC_NODISCARD constexpr auto height_b() const noexcept;
    //returns the height of c.
    ATOMIC_NODISCARD constexpr auto height_c() const noexcept;

    //returns the area of the triangle.
    ATOMIC_NODISCARD constexpr auto area() const noexcept;
    //returns the perimeter of the triangle.
    ATOMIC_NODISCARD constexpr auto perimeter() const noexcept;
    //returns the semi-perimeter of the triangle.
    ATOMIC_NODISCARD constexpr auto semiperimeter() const noexcept;
    //returns the inradius of the triangle.
    ATOMIC_NODISCARD constexpr auto inradius() const noexcept;
    //returns the circumradius of the triangle.
    ATOMIC_NODISCARD constexpr auto circumradius() const noexcept;
    //returns the centroid of the triangle.
    ATOMIC_NODISCARD constexpr auto centroid() const noexcept;

  public:
    linalg::fvector2<T> a;
    linalg::fvector2<T> b;
    linalg::fvector2<T> c;
  };

  template<typename T>
  constexpr triangle<T>::triangle(const T &a1, const T &a2, const T &b1, const T &b2, const T &c1, const T &c2)
    : a({ a1, a2 }), b({ b1, b2 }), c({ c1, c2 })
  {
    atomic::detail::trace("Created triangle.");
  }

  template<typename T>
  constexpr triangle<T>::triangle(const linalg::fvector2<T> &_a, const linalg::fvector2<T> &_b, const linalg::fvector2<T> &_c)
    : a(_a), b(_b), c(_c)
  {
    atomic::detail::trace("Created triangle.");
  }

  template<typename T>
  void triangle<T>::translate(const linalg::fvector2<T> &translation)
  {
    a[0] += translation[0];
    a[1] += translation[1];
    b[0] += translation[0];
    b[1] += translation[1];
    c[0] += translation[0];
    c[1] += translation[1];
  }

  template<typename T>
  constexpr auto triangle<T>::faces() const noexcept
  {
    return 2;
  }

  template<typename T>
  constexpr auto triangle<T>::vertices() const noexcept
  {
    return 3;
  }

  template<typename T>
  constexpr auto triangle<T>::edges() const noexcept
  {
    return 3;
  }

  template<typename T>
  constexpr auto triangle<T>::side_a() const noexcept
  {
    const auto lhs = (b[0] - c[0]) * (b[0] - c[0]);
    const auto rhs = (b[1] - c[1]) * (b[1] - c[1]);
    return std::sqrt(lhs + rhs);
  }

#include <iostream>

  template<typename T>
  constexpr auto triangle<T>::side_b() const noexcept
  {
    const auto lhs = (a[0] - c[0]) * (a[0] - c[0]);
    const auto rhs = (a[1] - c[1]) * (a[1] - c[1]);
    return std::sqrt(lhs + rhs);
  }

  template<typename T>
  constexpr auto triangle<T>::side_c() const noexcept
  {
    const auto lhs = (a[0] - b[0]) * (a[0] - b[0]);
    const auto rhs = (a[1] - b[1]) * (a[1] - b[1]);
    return std::sqrt(lhs + rhs);
  }

  template<typename T>
  constexpr auto triangle<T>::angle_a() const noexcept
  {
    const auto ma = side_a();
    const auto mb = side_b();
    const auto mc = side_c();

    const auto lhs = (mb * mb) + (mc * mc) - (ma * ma);
    const auto rhs = (2 * mb * mc);

    return std::acos((lhs / rhs));
  }

  template<typename T>
  constexpr auto triangle<T>::angle_b() const noexcept
  {
    const auto ma = side_a();
    const auto mb = side_b();
    const auto mc = side_c();

    const auto lhs = (ma * ma) + (mc * mc) - (mb * mb);
    const auto rhs = (2 * ma * mc);

    return std::acos((lhs / rhs));
  }

  template<typename T>
  constexpr auto triangle<T>::angle_c() const noexcept
  {
  }

  template<typename T>
  constexpr auto triangle<T>::height_a() const noexcept
  {
    return (2 * area()) / side_a();
  }

  template<typename T>
  constexpr auto triangle<T>::height_b() const noexcept
  {
    return (2 * area()) / side_b();
  }

  template<typename T>
  constexpr auto triangle<T>::height_c() const noexcept
  {
    return (2 * area()) / side_c();
  }

  template<typename T>
  constexpr auto triangle<T>::area() const noexcept
  {
    const auto sp = semiperimeter();
    return std::sqrt(sp * (sp - side_a()) * (sp - side_b()) * (sp - side_c()));
  }

  template<typename T>
  constexpr auto triangle<T>::perimeter() const noexcept
  {
    return side_a() + side_b() + side_c();
  }

  template<typename T>
  constexpr auto triangle<T>::semiperimeter() const noexcept
  {
    return perimeter() / 2;
  }

  template<typename T>
  constexpr auto triangle<T>::inradius() const noexcept
  {
    return (area() / semiperimeter());
  }

  template<typename T>
  constexpr auto triangle<T>::circumradius() const noexcept
  {
    const auto lhs = (side_a() * side_b() * side_c());
    const auto rhs = 4 * (inradius() * semiperimeter());
    return (lhs / rhs);
  }

  template<typename T>
  constexpr auto triangle<T>::centroid() const noexcept
  {
    const auto x = (a[0] + b[0] + c[0]) / 3;
    const auto y = (a[1] + b[1] + c[1]) / 3;
    std::cout << x << '|' << y << '\n';
    return linalg::fvector2<T>({ x, y });
  }

}// namespace geometry
}// namespace atomic

#endif// ATOMIC_GEOMETRY_TRIANGLE_HPP
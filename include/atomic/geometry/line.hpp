#pragma once
#ifndef ATOMIC_GEOMETRY_LINE_HPP
#define ATOMIC_GEOMETRY_LINE_HPP

#include <atomic/linear-algebra/traits.hpp>
#include <atomic/linear-algebra/vector.hpp>

namespace atomic {
namespace geometry {

  template<typename T, std::size_t D>
  struct line;
  template<typename T>
  using line2 = line<T, 2>;
  template<typename T>
  using line3 = line<T, 3>;
  template<typename T>
  using line4 = line<T, 3>;

  template<typename T, std::size_t D>
  struct line
  {
    static_assert(linalg::is_scalar_element<T>::value, "Type must be arithmetic.");
    static_assert(D > 0, "Dimension size must be greater than 0!");

  public:
    constexpr line() = default;
    constexpr line(line &) = default;
    constexpr line(line &&) noexcept = default;
    constexpr line &operator=(const line &lhs) = default;
    constexpr line &operator=(line &&lhs) noexcept = default;
    ~line() = default;

    constexpr line(const T _gradient, T _intercept, const linalg::fvector<T, D> _direction);

  public:
    T gradient = 0;
    T intercept = 0;
    linalg::fvector<T, D> direction;
  };

  template<typename T, std::size_t D>
  constexpr line<T, D>::line(const T _gradient, T _intercept, const linalg::fvector<T, D> _direction)
    : gradient(_gradient), intercept(_intercept), direction(_direction)
  {
    atomic::detail::trace("Created line", D);
  }

}// namespace geometry
}// namespace atomic

#endif// ATOMIC_GEOMETRY_LINE_HPP
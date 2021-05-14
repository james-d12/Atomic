#pragma once
#ifndef ATOMIC_GEOMETRY_CIRCLE_HPP
#define ATOMIC_GEOMETRY_CIRCLE_HPP

#include <atomic/math/constants.hpp>
#include <atomic/linear-algebra/traits.hpp>
#include <atomic/linear-algebra/vector.hpp>

namespace atomic {
namespace geometry {

  template<typename T>
  class circle
  {
    static_assert(linalg::is_scalar_element<T>::value, "circle template parameter must be a scalar type!");

  public:
    constexpr circle() = default;
    constexpr circle(circle &) = default;
    constexpr circle(circle &&) noexcept = default;
    ~circle() = default;

    constexpr circle(const T &cx, const T &cy, const T &_radius);
    constexpr circle(const linalg::fvector2<T> &_centre, const T &_radius);

    ATOMIC_NODISCARD constexpr auto area() const noexcept;
    ATOMIC_NODISCARD constexpr auto circumference() const noexcept;
    ATOMIC_NODISCARD constexpr auto diameter() const noexcept;

    ATOMIC_NODISCARD constexpr auto arc_length(const double angle) const noexcept;
    ATOMIC_NODISCARD constexpr auto chord_length(const double angle) const noexcept;
    ATOMIC_NODISCARD constexpr auto segment_area(const double angle) const noexcept;
    ATOMIC_NODISCARD constexpr auto segment_height(const double angle) const noexcept;

  public:
    linalg::fvector2<T> centre;
    T radius = 0;
  };

  template<typename T>
  constexpr circle<T>::circle(const T &cx, const T &cy, const T &_radius)
    : centre({ cx, cy }), radius(_radius)
  {
    atomic::detail::trace("Created Circle.");
  }

  template<typename T>
  constexpr circle<T>::circle(const linalg::fvector2<T> &_centre, const T &_radius)
    : centre(_centre), radius(_radius)
  {
    atomic::detail::trace("Created Circle.");
  }

  template<typename T>
  constexpr auto circle<T>::area() const noexcept
  {
    return math::constants::PI * (radius * radius);
  }

  template<typename T>
  constexpr auto circle<T>::circumference() const noexcept
  {
    return math::constants::PI * (radius * 2);
  }

  template<typename T>
  constexpr auto circle<T>::diameter() const noexcept
  {
    return (radius * 2);
  }

  template<typename T>
  constexpr auto circle<T>::arc_length(const double angle) const noexcept
  {
    return angle * radius;
  }

  template<typename T>
  constexpr auto circle<T>::chord_length(const double angle) const noexcept
  {
    return (2 * radius) * std::sin(angle / 2);
  }

  template<typename T>
  constexpr auto circle<T>::segment_area(const double angle) const noexcept
  {
    return 1 / 2 * (radius * radius) * (angle - std::sin(angle));
  }

  template<typename T>
  constexpr auto circle<T>::segment_height(const double angle) const noexcept
  {
    return radius * (1 - std::cos(angle / 2));
  }

}// namespace geometry
}// namespace atomic

#endif// ATOMIC_GEOMETRY_CIRCLE_HPP
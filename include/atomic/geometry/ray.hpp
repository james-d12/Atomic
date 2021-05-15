#ifndef ATOMIC_GEOMETRY_RAY_HPP
#define ATOMIC_GEOMETRY_RAY_HPP

#include "atomic/linear-algebra/traits.hpp"
#include "atomic/linear-algebra/vector.hpp"

namespace atomic {
namespace geometry {

  template<class T, std::size_t D>
  struct ray;
  template<typename T>
  using ray2 = ray<T, 2>;
  template<typename T>
  using ray3 = ray<T, 3>;
  template<typename T>
  using ray4 = ray<T, 4>;

  template<typename T, std::size_t D>
  struct ray
  {
    static_assert(linalg::is_scalar_element<T>::value, "Type must be arithmetic.");
    static_assert(D > 0, "Dimension size must be greater than 0!");

  public:
    constexpr ray() = default;
    constexpr ray(ray &) = default;
    constexpr ray(ray &&) noexcept = default;
    constexpr ray &operator=(const ray &lhs) = default;
    constexpr ray &operator=(ray &&lhs) noexcept = default;
    ~ray() = default;

    constexpr ray(const linalg::fvector<T, D> _origin, const linalg::fvector<T, D> _direction);

  public:
    linalg::fvector<T, D> origin;
    linalg::fvector<T, D> direction;
  };

  template<typename T, std::size_t D>
  constexpr ray<T, D>::ray(const linalg::fvector<T, D> _origin, const linalg::fvector<T, D> _direction)
    : origin(_origin), direction(_direction)
  {
    atomic::detail::trace("Created ray", D);
  }

}// namespace geometry
}// namespace atomic

#endif// ATOMIC_GEOMETRY_RAY_HPP
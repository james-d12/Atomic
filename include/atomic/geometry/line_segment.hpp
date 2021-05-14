#ifndef ATOMIC_GEOMETRY_LINE_SEGMENT_HPP
#define ATOMIC_GEOMETRY_LINE_SEGMENT_HPP

#include "atomic/linear-algebra/traits.hpp"
#include "atomic/linear-algebra/vector.hpp"

namespace atomic {
namespace geometry {

  template<typename T, std::size_t D>
  struct line_segment;
  template<typename T>
  using line_segment2 = line_segment<T, 2>;
  template<typename T>
  using line_segment3 = line_segment<T, 3>;
  template<typename T>
  using line_segment4 = line_segment<T, 3>;

  template<typename T, std::size_t D>
  struct line_segment
  {
    static_assert(linalg::is_scalar_element<T>::value, "Type must be arithmetic.");
    static_assert(D > 0, "Dimension size must be greater than 0!");

  public:
    constexpr line_segment() = default;
    constexpr line_segment(line_segment &) = default;
    constexpr line_segment(line_segment &&) noexcept = default;
    constexpr line_segment &operator=(const line_segment &lhs) = default;
    constexpr line_segment &operator=(line_segment &&lhs) noexcept = default;
    ~line_segment() = default;

    constexpr line_segment(const linalg::fvector<T, D> _start, const linalg::fvector<T, D> _end);

  public:
    linalg::fvector<T, D> start;
    linalg::fvector<T, D> end;
  };

  template<typename T, std::size_t D>
  constexpr line_segment<T, D>::line_segment(const linalg::fvector<T, D> _start, const linalg::fvector<T, D> _end)
    : start(_start), end(_end)
  {
    atomic::detail::trace("Created line_segment", D);
  }

}// namespace geometry
}// namespace atomic

#endif// ATOMIC_GEOMETRY_LINE_SEGMENT_HPP
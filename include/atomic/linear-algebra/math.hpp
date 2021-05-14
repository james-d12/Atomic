#ifndef ATOMIC_MATH_LINEAR_ALGEBRA_MATH_HPP
#define ATOMIC_MATH_LINEAR_ALGEBRA_MATH_HPP

#include "atomic/linear-algebra/vector.hpp"

namespace atomic {
namespace linalg {

  template<class ENG1, class ENG2>
  ATOMIC_NODISCARD constexpr auto dot_product(const vector<ENG1> &lhs, const vector<ENG2> &rhs)
  {
    atomic::detail::assertion(lhs.dimensions() == rhs.dimensions(), "Vector dimensions must be equal for dot product calculation.");

    using type = decltype(lhs[0] * rhs[0]);
    type sum = 0;
    typename ENG1::size_type index = 0;
    std::for_each(lhs.begin(), lhs.end(), [&](const auto &n) { sum += (n * rhs[index]); index++; });
    return sum;
  }

  template<class ENG1, class ENG2>
  ATOMIC_NODISCARD constexpr auto dot_product(const vector<ENG1> &lhs, const vector<ENG2> &rhs, double angle)
  {
    atomic::detail::assertion(lhs.dimensions() == rhs.dimensions(), "Vector dimensions must be equal for dot product calculation.");
    return (lhs.length() * rhs.length() * std::cos(angle));
  }

  template<class ENG1, class ENG2>
  ATOMIC_NODISCARD constexpr auto cross_product(const vector<ENG1> &lhs, const vector<ENG2> &rhs)
  {
    atomic::detail::assertion((lhs.dimensions() == 3 && rhs.dimensions() == 3), "Vectors must be 3 dimensional for cross product calculation.");
    auto x = (lhs[1] * rhs[2]) - (lhs[2] * rhs[1]);
    auto y = (lhs[2] * rhs[0]) - (lhs[0] * rhs[2]);
    auto z = (lhs[0] * rhs[1]) - (lhs[1] * rhs[0]);
    using result_type = decltype(detail::vector_engine_promotion(lhs.engine(), rhs.engine()));
    return vector<result_type>({ x, y, z });
  }

  template<class ENG1, class ENG2>
  ATOMIC_NODISCARD constexpr auto cross_product(const vector<ENG1> &lhs, const vector<ENG2> &rhs, double angle)
  {
    atomic::detail::assertion((lhs.dimensions() == 3 && rhs.dimensions() == 3), "Vectors must be 3 dimensional for cross product calculation.");
    auto scalar = lhs.length() * rhs.length() * std::sin(angle);

    using result_type = decltype(detail::vector_engine_promotion(lhs.engine(), rhs.engine()));
    vector<result_type> unit_vector = { 1, 1, 1 };
    return (unit_vector * scalar);
  }

  template<class ENG1, class ENG2>
  ATOMIC_NODISCARD constexpr auto angle_between(const vector<ENG1> &lhs, const vector<ENG2> &rhs)
  {
    auto dot_prod = dot_product(lhs, rhs);
    auto length = lhs.length() * rhs.length();
    return (dot_prod / length);
  }

  template<class ENG1, class ENG2, class ENG3>
  ATOMIC_NODISCARD constexpr auto scalar_triplet_product(const vector<ENG1> &v1, const vector<ENG2> &v2, const vector<ENG3> &v3)
  {
    auto cross_prod = cross_product(v1, v2);
    return (dot_product(v3, cross_prod));
  }

  template<class ENG>
  ATOMIC_NODISCARD constexpr auto direction_cosine_alpha(const vector<ENG> &v)
  {
    atomic::detail::assertion(v.dimensions() == 3 || v.dimensions() == 2, "Vector must be 2/3 dimensional for this calculation.");
    return (v[0] / v.length());
  }

  template<class ENG>
  ATOMIC_NODISCARD constexpr auto direction_cosine_beta(const vector<ENG> &v)
  {
    atomic::detail::assertion(v.dimensions() == 3 || v.dimensions() == 2, "Vector must be 2/3 dimensional for this calculation.");
    return (v[1] / v.length());
  }

  template<class ENG>
  ATOMIC_NODISCARD constexpr auto direction_cosine_gamma(const vector<ENG> &v)
  {
    atomic::detail::assertion(v.dimensions() == 3, "Vector must be 3 dimensional for this calculation.");
    return (v[2] / v.length());
  }

  template<class ENG1, class ENG2>
  ATOMIC_NODISCARD constexpr auto vector_projection(const vector<ENG1> &lhs, const vector<ENG2> &rhs)
  {
    return (dot_product(lhs, rhs) / rhs.length());
  }

  template<class ENG1, class ENG2>
  ATOMIC_NODISCARD constexpr auto scalar_projection(const vector<ENG1> &lhs, const vector<ENG2> &rhs)
  {
    auto dot = dot_product(lhs, rhs);
    auto multiplier = dot / rhs.length_squared();
    return;
  }

  template<class ENG1, class ENG2>
  ATOMIC_NODISCARD constexpr bool are_orthogonal(const vector<ENG1> &lhs, const vector<ENG2> &rhs)
  {
    return (dot_product(lhs, rhs) == 0);
  }

  template<class ENG1, class ENG2>
  ATOMIC_NODISCARD constexpr bool are_collinear(const vector<ENG1> &lhs, const vector<ENG2> &rhs)
  {
    if (lhs.dimensions() == 2 && rhs.dimensions() == 2) {
      return (lhs[0] / rhs[0] == lhs[1] / rhs[1]);
    } else if (lhs.dimensions() == 3 && rhs.dimensions() == 3) {
      return (lhs[0] / rhs[0] == lhs[1] / rhs[1] == lhs[2] / rhs[2]);
    } else {
      return false;
    }
  }

  template<class ENG1, class ENG2, class ENG3>
  ATOMIC_NODISCARD constexpr bool are_coplanar(const vector<ENG1> &v1, const vector<ENG2> &v2, const vector<ENG3> &v3)
  {
    return (scalar_triplet_product(v1, v2, v3) == 0);
  }

}// namespace linalg
}// namespace atomic

#endif// ATOMIC_MATH_LINEAR_ALGEBRA_MATH_HPP
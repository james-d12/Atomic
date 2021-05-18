/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#ifndef ATOMIC_CORE_UTILITY_HPP
#define ATOMIC_CORE_UTILITY_HPP

#include <cmath>
#include <cstddef>
#include <iostream>

#include "atomic/core/logging.hpp"

namespace atomic {
namespace detail {

  template<typename T>
  static inline auto out_of_bounds(const T index, const size_t upper_bound)
  {
    return static_cast<bool>(index > upper_bound || index < 0);
  }

  template<typename T1, typename T2>
  static inline auto are_same(T1 num1, T2 num2)
  {
    return (num1 - num2) <= 0;
  }

  template<>
  inline auto are_same<float, float>(float num1, float num2)
  {
    return fabsf(num1 - num2) < ATOMIC_FLT_EPSILON;
  }

  template<>
  inline auto are_same<double, double>(double num1, double num2)
  {
    return fabs(num1 - num2) < static_cast<double>(ATOMIC_FLT_EPSILON);
  }

  template<>
  inline auto are_same<long double, long double>(long double num1, long double num2)
  {
    return fabsl(num1 - num2) < static_cast<long double>(ATOMIC_FLT_EPSILON);
  }

  template<typename T1, typename T2>
  static constexpr auto min(const T1 &lhs, const T2 &rhs)
  {
    static_assert(std::is_arithmetic<T1>::value && std::is_arithmetic<T2>::value, "Types must be arithmetic.");
    return (lhs <= rhs) ? lhs : rhs;
  }

  template<typename T1, typename T2>
  static constexpr auto max(const T1 &lhs, const T2 &rhs)
  {
    static_assert(std::is_arithmetic<T1>::value && std::is_arithmetic<T2>::value, "Types must be arithmetic.");
    return (lhs >= rhs) ? lhs : rhs;
  }

}// namespace detail
}// namespace atomic

#endif// ATOMIC_CORE_UTILITY_HPP
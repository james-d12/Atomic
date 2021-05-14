#ifndef ATOMIC_MATH_SEQUENCE_HPP
#define ATOMIC_MATH_SEQUENCE_HPP

#include <array>
#include "atomic/core/utility.hpp"

namespace atomic {
namespace math {

  template<typename T, std::size_t S>
  static constexpr auto square_sequence(const T &num)
  {
    std::array<T, S> sequence;
    auto temp = num;
    for (std::size_t i = 0; i < S; ++i) {
      sequence[i] = temp;
      temp *= temp;
    }
    return sequence;
  }

  template<typename T, std::size_t S>
  constexpr int factorial(const T &num)
  {
    static_assert(std::is_integral<T>::value, "Type must be integral for factorial calculation.");
    return num ? (num * factorial<S>(num - 1)) : 1;
  }

}// namespace math
}// namespace atomic

#endif// ATOMIC_MATH_SEQUENCE_HPP
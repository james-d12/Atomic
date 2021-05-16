#ifndef ATOMIC_LINEAR_ALGEBRA_QUARTERNION_OPERATOR_HPP
#define ATOMIC_LINEAR_ALGEBRA_QUARTERNION_OPERATOR_HPP

#include <algorithm>

namespace atomic {
namespace linalg {
  namespace detail {
    template<class FwdIt1, class FwdIt2>
    auto quarternion_equal(FwdIt1 first1, FwdIt1 last1, FwdIt2 first2, FwdIt2 last2) noexcept
    {
      unsigned int count = 0;
      while (first1 != last1) {
        if (first2 == last2 || !atomic::detail::are_same(*first1, *first2)) { count++; }
        ++first1;
        ++first2;
      }
      return count == 0;
    }

    template<class FwdIt1, class FwdIt2>
    auto quarternion_less_than(FwdIt1 first1, FwdIt1 last1, FwdIt2 first2, FwdIt2 last2) noexcept
    {
      unsigned int count = 0;
      while (first1 != last1) {
        if (first2 == last2 || (*first1 >= *first2)) { count++; }
        ++first1;
        ++first2;
      }
      return count == 0;
    }

  }// namespace detail
}// namespace linalg
}// namespace atomic

#endif// ATOMIC_LINEAR_ALGEBRA_QUARTERNION_OPERATOR_HPP
#ifndef ATOMIC_MATH_LINEAR_ALGEBRA_MATRIX_ENGINE_OPERATOR_HELPER_HPP
#define ATOMIC_MATH_LINEAR_ALGEBRA_MATRIX_ENGINE_OPERATOR_HELPER_HPP

#include "atomic/linear-algebra/traits.hpp"
#include "atomic/linear-algebra/matrix_order.hpp"

namespace atomic {
namespace linalg {
  namespace detail {

    static constexpr auto calculate_index(const size_t i, const size_t j, const size_t rows, const MatrixOrder &order)
    {
      return (order == MatrixOrder::Row) ? j + (i * rows) : i + (j * rows);
    }

    template<class ENG1, class ENG2, class ENG3>
    inline void matrix_engine_addition_helper(const ENG1 &lhs, const ENG2 &rhs, ENG3 &src)
    {
      using size_type = typename ENG3::size_type;

      size_type index = 0;
      for (size_type i = 0; i < src.rows(); ++i) {
        for (size_type j = 0; j < src.columns(); ++j) {
          index = calculate_index(i, j, src.rows(), src.order());
          src[index] = lhs[index] + rhs[index];
        }
      }
    }

    template<class ENG1, class ENG2>
    inline void matrix_engine_subtraction_helper(const ENG1 &engine, ENG2 &src)
    {
      using size_type = typename ENG1::size_type;
      size_type index = 0;

      for (size_type i = 0; i < engine.rows(); ++i) {
        for (size_type j = 0; j < engine.columns(); ++j) {
          index = calculate_index(i, j, engine.rows(), engine.order());
          src[index] -= engine[index];
        }
      }
    }

    template<class ENG1, class ENG2, class ENG3>
    inline void matrix_engine_multiplication_row(const ENG1 &lhs, const ENG2 &rhs, ENG3 &src)
    {
      using size_type = typename ENG1::size_type;
      using result_type = element_promotion_t<typename ENG1::type, typename ENG2::type>;

      const auto lhs_rows = lhs.rows();
      const auto lhs_columns = lhs.columns();

      for (size_type i = 0; i < lhs_rows; ++i) {
        for (size_type j = 0; j < lhs_columns; ++j) {
          result_type sum = 0;
          for (size_type k = 0; k < lhs_rows; ++k) {
            sum += lhs[k + (i * lhs_rows)] * rhs[j + (k * lhs_rows)];
          }
          src[j + i * lhs_rows] = sum;
        }
      }
    }

    template<class ENG1, class ENG2, class ENG3>
    inline void matrix_engine_multiplication_column(const ENG1 &lhs, const ENG2 &rhs, ENG3 &src)
    {
      using size_type = typename ENG1::size_type;
      using result_type = element_promotion_t<typename ENG1::type, typename ENG2::type>;

      const auto lhs_rows = lhs.rows();
      const auto lhs_columns = lhs.columns();

      for (size_type i = 0; i < lhs_rows; ++i) {
        for (size_type j = 0; j < lhs_columns; ++j) {
          result_type sum = 0;
          for (size_type k = 0; k < lhs_rows; ++k) {
            sum += lhs[j + (k * lhs_rows)] * rhs[k + (i * lhs_rows)];
          }
          src[j + i * lhs_rows] = sum;
        }
      }
    }

    template<class ENG1, class ENG2, class ENG3>
    inline void matrix_engine_multiplication(const ENG1 &lhs, const ENG2 &rhs, ENG3 &src)
    {
      switch (src.order()) {
      case MatrixOrder::Row:
        matrix_engine_multiplication_row(lhs, rhs, src);
        break;
      case MatrixOrder::Column:
        matrix_engine_multiplication_column(lhs, rhs, src);
        break;
      }
    }

    template<class ENG1, class ENG2>
    inline auto matrix_engine_addition(const ENG1 &lhs, const ENG2 &rhs)
    {
      auto src = matrix_engine_promotion(lhs, rhs);
      matrix_engine_addition_helper(lhs, rhs, src);
      return src;
    }

    template<class ENG1, class ENG2>
    inline auto matrix_engine_subtraction(const ENG1 &lhs, const ENG2 &rhs)
    {
      auto src = matrix_engine_promotion(lhs, rhs);
      std::copy(lhs.cbegin(), lhs.cend(), src.begin());
      matrix_engine_subtraction_helper(rhs, src);
      return src;
    }

    template<class ENG1, class ENG2>
    inline auto matrix_engine_multiplication(const ENG1 &lhs, const ENG2 &rhs)
    {
      auto src = matrix_engine_promotion(lhs, rhs);
      matrix_engine_multiplication(lhs, rhs, src);
      return src;
    }

    template<class FwdIt1, class FwdIt2>
    auto matrix_engine_equal(FwdIt1 first1, FwdIt1 last1, FwdIt2 first2, FwdIt2 last2) noexcept
    {
      unsigned int count = 0;
      while (first1 != last1) {
        if (first2 == last2 || !atomic::detail::are_same(*first1, *first2)) { count++; }
        ++first1;
        ++first2;
      }
      return count == 0;
    }

  }// namespace detail
}// namespace linalg
}// namespace atomic

#endif// ATOMIC_MATH_LINEAR_ALGEBRA_MATRIX_ENGINE_OPERATOR_HELPER_HPP
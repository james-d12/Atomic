#pragma once
#ifndef ATOMIC_MATH_LINEAR_ALGEBRA_MATRIX_HPP
#define ATOMIC_MATH_LINEAR_ALGEBRA_MATRIX_HPP

#include <atomic/linear-algebra/matrix_engine_operator.hpp>
#include <cmath>

namespace atomic {
namespace linalg {

  template<class ENG>
  class matrix;
  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O = MatrixOrder::Row>
  using fmatrix = matrix<fixed_matrix_engine<T, R, C, O>>;
  template<typename T, enum MatrixOrder O = MatrixOrder::Row>
  using fmatrix2 = matrix<fixed_matrix_engine<T, 2, 2, O>>;
  template<typename T, enum MatrixOrder O = MatrixOrder::Row>
  using fmatrix3 = matrix<fixed_matrix_engine<T, 3, 3, O>>;
  template<typename T, enum MatrixOrder O = MatrixOrder::Row>
  using fmatrix4 = matrix<fixed_matrix_engine<T, 4, 4, O>>;
  template<typename T, enum MatrixOrder O = MatrixOrder::Row>
  using dmatrix = matrix<dynamic_matrix_engine<T, O>>;

  template<typename T, std::size_t R, std::size_t C>
  using frmatrix = matrix<fixed_matrix_engine<T, R, C, MatrixOrder::Row>>;
  template<typename T, std::size_t R, std::size_t C>
  using fcmatrix = matrix<fixed_matrix_engine<T, R, C, MatrixOrder::Column>>;

  template<class ENG>
  class matrix
  {
    static_assert(is_engine_matrix<ENG>::value, "Engine parameter must be a matrix engine.");

  public:
    using type = typename ENG::type;
    using reference = typename ENG::reference;
    using const_reference = typename ENG::const_reference;
    using size_type = typename ENG::size_type;
    using storage_type = typename ENG::storage_type;
    using engine_type = typename ENG::engine_type;

    using iterator = typename ENG::iterator;
    using const_iterator = typename ENG::const_iterator;
    using reverse_iterator = typename ENG::reverse_iterator;
    using const_reverse_iterator = typename ENG::const_reverse_iterator;

    constexpr matrix(const matrix &) = default;
    constexpr matrix &operator=(const matrix &) = default;
    constexpr matrix(matrix &&) noexcept = default;
    constexpr matrix &operator=(matrix &&) noexcept = default;
    ~matrix() = default;

    constexpr matrix();
    constexpr explicit matrix(const storage_type data);
    constexpr matrix(const std::initializer_list<type> data);
    constexpr explicit matrix(const ENG &engine);
    constexpr matrix &operator=(const storage_type data);
    constexpr matrix &operator=(const std::initializer_list<type> data);
    constexpr matrix &operator=(const ENG &engine);

    ATOMIC_NODISCARD constexpr reference operator[](const size_type index);
    ATOMIC_NODISCARD constexpr const_reference operator[](const size_type index) const;

    ATOMIC_NODISCARD constexpr reference operator()(const size_type i, const size_type j);
    ATOMIC_NODISCARD constexpr const_reference operator()(const size_type i, const size_type j) const;

    ATOMIC_NODISCARD constexpr auto order() const noexcept;
    ATOMIC_NODISCARD constexpr auto engine() const noexcept;
    ATOMIC_NODISCARD constexpr auto data() const noexcept;
    ATOMIC_NODISCARD constexpr auto dimensions() const noexcept;
    ATOMIC_NODISCARD constexpr auto capacity() const noexcept;
    ATOMIC_NODISCARD constexpr auto rows() const noexcept;
    ATOMIC_NODISCARD constexpr auto rows_capacity() const noexcept;
    ATOMIC_NODISCARD constexpr auto columns() const noexcept;
    ATOMIC_NODISCARD constexpr auto columns_capacity() const noexcept;

    ATOMIC_NODISCARD constexpr auto get_row(size_type index) const;
    ATOMIC_NODISCARD constexpr auto get_column(size_type index) const;

    constexpr void fill(const_reference n);

    void print() const noexcept;

    void tranpose();
    ATOMIC_NODISCARD constexpr auto transposed() const;

  private:
    ENG m_engine;
  };

  template<class ENG>
  constexpr matrix<ENG>::matrix()
  {
    atomic::detail::trace("Created matrix", rows(), "x", columns());
  }

  template<class ENG>
  constexpr matrix<ENG>::matrix(const storage_type data)
    : m_engine(data)
  {
    atomic::detail::trace("Created matrix", rows(), "x", columns(), " with storage_type: ", typeid(data).name());
  }

  template<class ENG>
  constexpr matrix<ENG>::matrix(const std::initializer_list<type> data)
    : m_engine(data)
  {
    atomic::detail::trace("Created matrix", rows(), "x", columns(), " with storage_type: ", typeid(data).name());
  }

  template<class ENG>
  constexpr matrix<ENG>::matrix(const ENG &engine)
    : m_engine(engine)
  {
    atomic::detail::trace("Created matrix", rows(), "x", columns(), " with engine_type: ", typeid(engine).name());
  }

  template<class ENG>
  constexpr matrix<ENG> &
    matrix<ENG>::operator=(const storage_type data)
  {
    m_engine = data;
    return *this;
  }

  template<class ENG>
  constexpr matrix<ENG> &
    matrix<ENG>::operator=(const std::initializer_list<type> data)
  {
    m_engine = data;
    return *this;
  }

  template<class ENG>
  constexpr matrix<ENG> &
    matrix<ENG>::operator=(const ENG &engine)
  {
    m_engine = engine;
    return *this;
  }

  template<class ENG>
  constexpr typename matrix<ENG>::reference
    matrix<ENG>::operator[](const size_type index)
  {
    return m_engine[index];
  }

  template<class ENG>
  constexpr typename matrix<ENG>::const_reference
    matrix<ENG>::operator[](const size_type index) const
  {
    return m_engine[index];
  }

  template<class ENG>
  constexpr typename matrix<ENG>::reference
    matrix<ENG>::operator()(const size_type i, const size_type j)
  {
    return m_engine(i, j);
  }

  template<class ENG>
  constexpr typename matrix<ENG>::const_reference
    matrix<ENG>::operator()(const size_type i, const size_type j) const
  {
    return m_engine(i, j);
  }

  template<class ENG>
  constexpr auto matrix<ENG>::order() const noexcept
  {
    return m_engine.order();
  }

  template<class ENG>
  constexpr auto matrix<ENG>::engine() const noexcept
  {
    return m_engine;
  }

  template<class ENG>
  constexpr auto matrix<ENG>::data() const noexcept
  {
    return m_engine.data();
  }

  template<class ENG>
  constexpr auto matrix<ENG>::dimensions() const noexcept
  {
    return m_engine.size();
  }

  template<class ENG>
  constexpr auto matrix<ENG>::capacity() const noexcept
  {
    return m_engine.capacity();
  }

  template<class ENG>
  constexpr auto matrix<ENG>::rows() const noexcept
  {
    return m_engine.rows();
  }

  template<class ENG>
  constexpr auto matrix<ENG>::rows_capacity() const noexcept
  {
    return m_engine.rows_capacity();
  }

  template<class ENG>
  constexpr auto matrix<ENG>::columns() const noexcept
  {
    return m_engine.columns();
  }

  template<class ENG>
  constexpr auto matrix<ENG>::columns_capacity() const noexcept
  {
    return m_engine.columns_capacity;
  }

  template<class ENG>
  constexpr void matrix<ENG>::fill(const_reference n)
  {
    m_engine.fill(n);
  }

  template<class ENG>
  void matrix<ENG>::print() const noexcept
  {
    size_type index = 0;
    switch (order()) {
    case MatrixOrder::Row:
      for (size_type i = 0; i < rows(); ++i) {
        std::cout << "[ ";
        for (size_type j = 0; j < columns(); ++j) {
          index = j + (i * rows());
          std::cout << m_engine[index] << " ";
        }
        std::cout << "]\n";
      }
      break;
    case MatrixOrder::Column:
      for (size_type i = 0; i < rows(); ++i) {
        std::cout << "[ ";
        for (size_type j = 0; j < columns(); ++j) {
          index = i + (j * rows());
          std::cout << m_engine[index] << " ";
        }
        std::cout << "]\n";
      }
      break;
    default:
      break;
    }
  }

  template<class ENG1, class ENG2>
  inline auto operator+(const matrix<ENG1> &lhs, const matrix<ENG2> &rhs)
  {
    atomic::detail::assertion(lhs.dimensions() == rhs.dimensions(), "Matrices must be equal sizes to perform addition.");
    auto result_engine = detail::matrix_engine_addition(lhs.engine(), rhs.engine());
    using result_engine_type = decltype(result_engine);
    return matrix<result_engine_type>(result_engine);
  }

  template<class ENG1, class ENG2>
  inline auto operator-(const matrix<ENG1> &lhs, const matrix<ENG2> &rhs)
  {
    atomic::detail::assertion(lhs.dimensions() == rhs.dimensions(), "Matrices must be equal sizes to perform subtraction.");
    auto result_engine = detail::matrix_engine_subtraction(lhs.engine(), rhs.engine());
    using result_engine_type = decltype(result_engine);
    return matrix<result_engine_type>(result_engine);
  }

  template<class ENG1, class ENG2>
  inline auto operator*(const matrix<ENG1> &lhs, const matrix<ENG2> &rhs)
  {
    auto result_engine = detail::matrix_engine_multiplication(lhs.engine(), rhs.engine());
    using result_engine_type = decltype(result_engine);
    return matrix<result_engine_type>(result_engine);
  }

  template<class ENG1, class ENG2>
  inline auto operator==(const matrix<ENG1> &lhs, const matrix<ENG2> &rhs)
  {
    return;
  }

  template<class ENG1, class ENG2>
  inline auto operator!=(const matrix<ENG1> &lhs, const matrix<ENG2> &rhs)
  {
    return;
  }

}// namespace linalg
}// namespace atomic

#endif// ATOMIC_MATH_LINEAR_ALGEBRA_MATRIX_HPP
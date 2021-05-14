#ifndef ATOMIC_LINEAR_ALGEBRA_FIXED_MATRIX_ENGINE_HPP
#define ATOMIC_LINEAR_ALGEBRA_FIXED_MATRIX_ENGINE_HPP

#include <array>
#include "atomic/linear-algebra/matrix_order.hpp"
#include "atomic/linear-algebra/traits.hpp"

namespace atomic {
namespace linalg {

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O = MatrixOrder::Row>
  class fixed_matrix_engine
  {
    static_assert(is_scalar_element<T>::value, "fixed_matrix_engine template parameter must be a scalar type!");
    static_assert((R > 0 && C > 0), "Dimension size must be greater than 0!");

  public:
    using type = T;
    using reference = type &;
    using const_reference = const type &;
    using size_type = std::size_t;
    using storage_type = std::array<T, R * C>;
    using engine_type = fixed_matrix_engine_type;

    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;
    using reverse_iterator = typename storage_type::reverse_iterator;
    using const_reverse_iterator = typename storage_type::const_reverse_iterator;

    constexpr fixed_matrix_engine(const fixed_matrix_engine &) = default;
    constexpr fixed_matrix_engine &operator=(const fixed_matrix_engine &) = default;
    constexpr fixed_matrix_engine(fixed_matrix_engine &&) noexcept = default;
    constexpr fixed_matrix_engine &operator=(fixed_matrix_engine &&) noexcept = default;

    ~fixed_matrix_engine() = default;

    constexpr fixed_matrix_engine();
    constexpr fixed_matrix_engine(const storage_type &data);
    constexpr fixed_matrix_engine(const std::initializer_list<type> data);
    constexpr fixed_matrix_engine &operator=(const storage_type &data);
    constexpr fixed_matrix_engine &operator=(const std::initializer_list<type> data);

    ATOMIC_NODISCARD constexpr reference operator[](const size_type index);
    ATOMIC_NODISCARD constexpr const_reference operator[](const size_type index) const;
    ATOMIC_NODISCARD constexpr reference operator()(const size_type i, const size_type j);
    ATOMIC_NODISCARD constexpr const_reference operator()(const size_type i, const size_type j) const;

    constexpr auto begin() noexcept;
    constexpr auto begin() const noexcept;
    constexpr auto end() noexcept;
    constexpr auto end() const noexcept;

    ATOMIC_NODISCARD constexpr auto order() const noexcept;
    ATOMIC_NODISCARD constexpr auto data() const noexcept;
    ATOMIC_NODISCARD constexpr auto size() const noexcept;
    ATOMIC_NODISCARD constexpr auto capacity() const noexcept;
    ATOMIC_NODISCARD constexpr auto rows() const noexcept;
    ATOMIC_NODISCARD constexpr auto rows_capacity() const noexcept;
    ATOMIC_NODISCARD constexpr auto columns() const noexcept;
    ATOMIC_NODISCARD constexpr auto columns_capacity() const noexcept;

    constexpr void fill(const_reference n);

  private:
    storage_type m_data;
    static constexpr size_type m_rows = R;
    static constexpr size_type m_rows_capacity = R;
    static constexpr size_type m_columns = C;
    static constexpr size_type m_columns_capacity = C;
    static constexpr MatrixOrder m_order = O;

    constexpr auto index(const size_type i, const size_type j) const;
  };

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr fixed_matrix_engine<T, R, C, O>::fixed_matrix_engine()
  {
    m_data.fill(0);
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr fixed_matrix_engine<T, R, C, O>::fixed_matrix_engine(const storage_type &data)
    : m_data(data)
  {
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr fixed_matrix_engine<T, R, C, O>::fixed_matrix_engine(const std::initializer_list<type> data)
  {
    std::copy(std::begin(data), std::end(data), m_data.begin());
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr fixed_matrix_engine<T, R, C, O> &
    fixed_matrix_engine<T, R, C, O>::operator=(const storage_type &data)
  {
    m_data = data;
    return *this;
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr fixed_matrix_engine<T, R, C, O> &
    fixed_matrix_engine<T, R, C, O>::operator=(const std::initializer_list<type> data)
  {
    std::copy(std::begin(data), std::end(data), m_data.begin());
    return *this;
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr typename fixed_matrix_engine<T, R, C, O>::reference
    fixed_matrix_engine<T, R, C, O>::operator[](const size_type index)
  {
    return m_data[index];
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr typename fixed_matrix_engine<T, R, C, O>::const_reference
    fixed_matrix_engine<T, R, C, O>::operator[](const size_type index) const
  {
    return m_data[index];
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr typename fixed_matrix_engine<T, R, C, O>::reference
    fixed_matrix_engine<T, R, C, O>::operator()(const size_type i, const size_type j)
  {
    return m_data[index(i, j)];
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr typename fixed_matrix_engine<T, R, C, O>::const_reference
    fixed_matrix_engine<T, R, C, O>::operator()(const size_type i, const size_type j) const
  {
    return m_data[index(i, j)];
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::begin() noexcept
  {
    return m_data.begin();
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::begin() const noexcept
  {
    return m_data.begin();
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::end() noexcept
  {
    return m_data.end();
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::end() const noexcept
  {
    return m_data.end();
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::order() const noexcept
  {
    return m_order;
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::data() const noexcept
  {
    return m_data;
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::size() const noexcept
  {
    return m_rows * m_columns;
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::capacity() const noexcept
  {
    return m_rows_capacity * m_columns_capacity;
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::rows() const noexcept
  {
    return m_rows;
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::rows_capacity() const noexcept
  {
    return m_rows_capacity;
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::columns() const noexcept
  {
    return m_columns;
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::columns_capacity() const noexcept
  {
    return m_columns_capacity;
  }
  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr void fixed_matrix_engine<T, R, C, O>::fill(const_reference n)
  {
    m_data.fill(n);
  }

  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  constexpr auto fixed_matrix_engine<T, R, C, O>::index(const size_type i, const size_type j) const
  {
    switch (m_order) {
    case MatrixOrder::Row:
      return j + (i * m_rows);
    case MatrixOrder::Column:
      return i + (j * m_rows);
    default:
      return 0;
    }
  }

}// namespace linalg
}// namespace atomic

#endif// ATOMIC_LINEAR_ALGEBRA_FIXED_MATRIX_ENGINE_HPP
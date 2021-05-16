#ifndef ATOMIC_LINEAR_ALGEBRA_DYNAMIC_MATRIX_ENGINE_HPP
#define ATOMIC_LINEAR_ALGEBRA_DYNAMIC_MATRIX_ENGINE_HPP

#include <vector>
#include "atomic/linear-algebra/matrix_order.hpp"
#include "atomic/linear-algebra/traits.hpp"

namespace atomic {
namespace linalg {

  template<typename T, enum MatrixOrder O = MatrixOrder::Row>
  class dynamic_matrix_engine
  {
    static_assert(is_scalar_element<T>::value, "dynamic_matrix_engine template parameter must be a scalar type!");

  public:
    using type = T;
    using reference = type &;
    using const_reference = const type &;
    using size_type = std::size_t;
    using storage_type = std::vector<type>;
    using engine_type = resizable_matrix_engine_type;

    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;
    using reverse_iterator = typename storage_type::reverse_iterator;
    using const_reverse_iterator = typename storage_type::const_reverse_iterator;

    dynamic_matrix_engine() = default;
    dynamic_matrix_engine(const dynamic_matrix_engine &) = default;
    dynamic_matrix_engine &operator=(const dynamic_matrix_engine &) = default;
    dynamic_matrix_engine(dynamic_matrix_engine &&) noexcept = default;
    dynamic_matrix_engine &operator=(dynamic_matrix_engine &&) noexcept = default;
    ~dynamic_matrix_engine() = default;

    explicit dynamic_matrix_engine(size_type num, const_reference val);
    explicit dynamic_matrix_engine(const storage_type &data);
    dynamic_matrix_engine(const std::initializer_list<type> data);
    dynamic_matrix_engine &operator=(const storage_type &data);
    dynamic_matrix_engine &operator=(const std::initializer_list<type> data);

    ATOMIC_NODISCARD reference operator[](const size_type index);
    ATOMIC_NODISCARD const_reference operator[](const size_type index) const;
    ATOMIC_NODISCARD reference operator()(const size_type i, const size_type j);
    ATOMIC_NODISCARD const_reference operator()(const size_type i, const size_type j) const;

    ATOMIC_NODISCARD constexpr auto order() const noexcept;
    ATOMIC_NODISCARD auto data() const noexcept;
    ATOMIC_NODISCARD auto size() const noexcept;
    ATOMIC_NODISCARD auto capacity() const noexcept;
    ATOMIC_NODISCARD auto rows() const noexcept;
    ATOMIC_NODISCARD auto rows_capacity() const noexcept;
    ATOMIC_NODISCARD auto columns() const noexcept;
    ATOMIC_NODISCARD auto columns_capacity() const noexcept;

    void resize(const size_type rows, const size_type cols);
    void reserve(const size_type rows_capacity, const size_type cols_capacity);
    void resize_and_reserve(const size_type rows, const size_type rows_capacity, const size_type cols, const size_type cols_capacity);

    void fill(const_reference n);

  private:
    storage_type m_data;
    size_type m_rows = 0;
    size_type m_rows_capacity = 0;
    size_type m_columns = 0;
    size_type m_columns_capacity = 0;
    static constexpr MatrixOrder m_order = O;

    auto index(const size_type i, const size_type j) const;
  };

  template<typename T, enum MatrixOrder O>
  dynamic_matrix_engine<T, O>::dynamic_matrix_engine(const size_type num, const_reference val)
    : m_data(num, val)
  {
  }

  template<typename T, enum MatrixOrder O>
  dynamic_matrix_engine<T, O>::dynamic_matrix_engine(const storage_type &data)
    : m_data(data), m_rows(data.size())
  {
  }

  template<typename T, enum MatrixOrder O>
  dynamic_matrix_engine<T, O>::dynamic_matrix_engine(const std::initializer_list<type> data)
  {
    resize(data.size());
    std::copy(std::cbegin(data), std::cend(data), m_data.begin());
  }

  template<typename T, enum MatrixOrder O>
  dynamic_matrix_engine<T, O> &
    dynamic_matrix_engine<T, O>::operator=(const storage_type &data)
  {
    m_data = data;
    return *this;
  }

  template<typename T, enum MatrixOrder O>
  dynamic_matrix_engine<T, O> &
    dynamic_matrix_engine<T, O>::operator=(const std::initializer_list<type> data)
  {
    resize(data.size());
    std::copy(std::cbegin(data), std::cend(data), m_data.begin());
    return *this;
  }

  template<typename T, enum MatrixOrder O>
  typename dynamic_matrix_engine<T, O>::reference
    dynamic_matrix_engine<T, O>::operator[](const size_type index)
  {
    return m_data[index];
  }

  template<typename T, enum MatrixOrder O>
  typename dynamic_matrix_engine<T, O>::const_reference
    dynamic_matrix_engine<T, O>::operator[](const size_type index) const
  {
    return m_data[index];
  }

  template<typename T, enum MatrixOrder O>
  typename dynamic_matrix_engine<T, O>::reference
    dynamic_matrix_engine<T, O>::operator()(const size_type i, const size_type j)
  {
    return m_data[index(i, j)];
  }

  template<typename T, enum MatrixOrder O>
  typename dynamic_matrix_engine<T, O>::const_reference
    dynamic_matrix_engine<T, O>::operator()(const size_type i, const size_type j) const
  {
    return m_data[index(i, j)];
  }

  template<typename T, enum MatrixOrder O>
  constexpr auto dynamic_matrix_engine<T, O>::order() const noexcept
  {
    return m_order;
  }

  template<typename T, enum MatrixOrder O>
  auto dynamic_matrix_engine<T, O>::data() const noexcept
  {
    return m_data;
  }

  template<typename T, enum MatrixOrder O>
  auto dynamic_matrix_engine<T, O>::size() const noexcept
  {
    return m_rows + m_columns;
  }

  template<typename T, enum MatrixOrder O>
  auto dynamic_matrix_engine<T, O>::capacity() const noexcept
  {
    return (m_rows_capacity + m_columns_capacity);
  }

  template<typename T, enum MatrixOrder O>
  auto dynamic_matrix_engine<T, O>::rows() const noexcept
  {
    return m_rows;
  }

  template<typename T, enum MatrixOrder O>
  auto dynamic_matrix_engine<T, O>::rows_capacity() const noexcept
  {
    return m_rows_capacity;
  }

  template<typename T, enum MatrixOrder O>
  auto dynamic_matrix_engine<T, O>::columns() const noexcept
  {
    return m_columns;
  }

  template<typename T, enum MatrixOrder O>
  auto dynamic_matrix_engine<T, O>::columns_capacity() const noexcept
  {
    return m_columns_capacity;
  }


  template<typename T, enum MatrixOrder O>
  void dynamic_matrix_engine<T, O>::resize(const size_type rows, const size_type cols)
  {
    m_data.resize((rows * cols) * m_rows);
  }

  template<typename T, enum MatrixOrder O>
  void dynamic_matrix_engine<T, O>::reserve(const size_type rows_capacity, const size_type cols_capacity)
  {
    m_data.reserve((rows_capacity * cols_capacity) * m_rows);
  }

  template<typename T, enum MatrixOrder O>
  void dynamic_matrix_engine<T, O>::resize_and_reserve(const size_type rows, const size_type rows_capacity, const size_type cols, const size_type cols_capacity)
  {
    resize(rows, cols);
    reserve(rows_capacity, cols_capacity);
  }

  template<typename T, enum MatrixOrder O>
  void dynamic_matrix_engine<T, O>::fill(const_reference n)
  {
    m_data.fill(n);
  }

  template<typename T, enum MatrixOrder O>
  auto dynamic_matrix_engine<T, O>::index(const size_type i, const size_type j) const
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

#endif// ATOMIC_LINEAR_ALGEBRA_DYNAMIC_MATRIX_ENGINE_HPP
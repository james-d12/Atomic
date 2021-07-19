/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#ifndef ATOMIC_LINEAR_ALGEBRA_DYNAMIC_VECTOR_ENGINE_HPP
#define ATOMIC_LINEAR_ALGEBRA_DYNAMIC_VECTOR_ENGINE_HPP

#include <vector>
#include "atomic/linear-algebra/traits.hpp"

namespace atomic {
namespace linalg {

  template<typename T>
  class dynamic_vector_engine
  {
    static_assert(is_scalar_element<T>::value, "dynamic_vector_engine template parameter must be a scalar type!");

  public:
    using type = T;
    using pointer = type *;
    using reference = type &;
    using const_reference = const type &;
    using size_type = std::size_t;
    using storage_type = std::vector<type>;
    using engine_type = resizable_vector_engine_type;

    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;
    using reverse_iterator = typename storage_type::reverse_iterator;
    using const_reverse_iterator = typename storage_type::const_reverse_iterator;

    dynamic_vector_engine() = default;
    dynamic_vector_engine(const dynamic_vector_engine &) = default;
    dynamic_vector_engine &operator=(const dynamic_vector_engine &) = default;
    dynamic_vector_engine(dynamic_vector_engine &&) noexcept = default;
    dynamic_vector_engine &operator=(dynamic_vector_engine &&) noexcept = default;
    ~dynamic_vector_engine() = default;

    explicit dynamic_vector_engine(size_type num, const_reference val = type());
    explicit dynamic_vector_engine(const storage_type &data);
    dynamic_vector_engine(const std::initializer_list<type> data);
    dynamic_vector_engine &operator=(const storage_type &data);
    dynamic_vector_engine &operator=(const std::initializer_list<type> data);

    ATOMIC_NODISCARD reference operator[](const size_type index) noexcept;
    ATOMIC_NODISCARD const_reference operator[](const size_type index) const noexcept;

    auto begin() noexcept;
    auto begin() const noexcept;
    auto end() noexcept;
    auto end() const noexcept;

    auto rbegin() noexcept;
    auto rbegin() const noexcept;
    auto rend() noexcept;
    auto rend() const noexcept;

    auto cbegin() const noexcept;
    auto cend() const noexcept;
    auto crbegin() const noexcept;
    auto crend() const noexcept;

    ATOMIC_NODISCARD auto data() const noexcept;
    ATOMIC_NODISCARD auto size() const noexcept;
    ATOMIC_NODISCARD auto capacity() const noexcept;

    void resize(size_type size);
    void reserve(size_type capacity);
    void resize_and_reserve(size_type size, size_type capacity);

    void fill(const_reference n);

  private:
    storage_type m_data;
  };

  template<typename T>
  dynamic_vector_engine<T>::dynamic_vector_engine(const size_type num, const_reference val)
    : m_data(num, val)
  {
  }

  template<typename T>
  dynamic_vector_engine<T>::dynamic_vector_engine(const storage_type &data)
    : m_data(data)
  {
  }

  template<typename T>
  dynamic_vector_engine<T>::dynamic_vector_engine(const std::initializer_list<type> data)
  {
    std::fill(begin(), end(), T(0));
    resize(data.size());
    std::copy(std::cbegin(data), std::cend(data), m_data.begin());
  }

  template<typename T>
  dynamic_vector_engine<T> &
    dynamic_vector_engine<T>::operator=(const storage_type &data)
  {
    m_data = data;
    return *this;
  }

  template<typename T>
  dynamic_vector_engine<T> &
    dynamic_vector_engine<T>::operator=(const std::initializer_list<type> data)
  {
    resize(data.size());
    std::copy(std::cbegin(data), std::cend(data), m_data.begin());
    return *this;
  }

  template<typename T>
  typename dynamic_vector_engine<T>::reference
    dynamic_vector_engine<T>::operator[](const size_type index) noexcept
  {
    return m_data[index];
  }
  template<typename T>
  typename dynamic_vector_engine<T>::const_reference
    dynamic_vector_engine<T>::operator[](const size_type index) const noexcept
  {
    return m_data[index];
  }

  template<typename T>
  auto dynamic_vector_engine<T>::begin() noexcept
  {
    return m_data.begin();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::begin() const noexcept
  {
    return m_data.begin();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::end() noexcept
  {
    return m_data.end();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::end() const noexcept
  {
    return m_data.end();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::rbegin() noexcept
  {
    return m_data.rbegin();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::rbegin() const noexcept
  {
    return m_data.rbegin();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::rend() noexcept
  {
    return m_data.rend();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::rend() const noexcept
  {
    return m_data.rend();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::cbegin() const noexcept
  {
    return m_data.cbegin();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::cend() const noexcept
  {
    return m_data.cend();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::crbegin() const noexcept
  {
    return m_data.crbegin();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::crend() const noexcept
  {
    return m_data.crend();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::data() const noexcept
  {
    return m_data;
  }

  template<typename T>
  auto dynamic_vector_engine<T>::size() const noexcept
  {
    return m_data.size();
  }

  template<typename T>
  auto dynamic_vector_engine<T>::capacity() const noexcept
  {
    return m_data.capacity();
  }

  template<typename T>
  void dynamic_vector_engine<T>::resize(size_type size)
  {
    m_data.resize(size);
  }

  template<typename T>
  void dynamic_vector_engine<T>::reserve(size_type capacity)
  {
    m_data.reserve(capacity);
  }

  template<typename T>
  void dynamic_vector_engine<T>::resize_and_reserve(size_type size, size_type capacity)
  {
    resize(size);
    reserve(capacity);
  }

  template<typename T>
  void dynamic_vector_engine<T>::fill(const_reference n)
  {
    std::fill(m_data.begin(), m_data.end(), n);
  }


}// namespace linalg
}// namespace atomic


#endif// ATOMIC_LINEAR_ALGEBRA_DYNAMIC_VECTOR_ENGINE_HPP
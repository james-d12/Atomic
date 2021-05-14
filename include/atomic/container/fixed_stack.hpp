#pragma once
#ifndef ATOMIC_CONTAINER_FIXED_STACK_HPP
#define ATOMIC_CONTAINER_FIXED_STACK_HPP

#include <atomic/core/utility.hpp>
#include <type_traits>
#include <algorithm>
#include <array>

namespace atomic {
namespace container {

  template<typename T, std::size_t D>
  class fixed_stack
  {
    static_assert(D >= 1, "Fixed stack size must be greater than 0!.");
    static_assert(std::is_default_constructible<T>::value, "Fixed stack type must be default constructible");

  public:
    using type = T;
    using size_type = std::size_t;
    using pointer = T *;
    using reference = T &;
    using const_reference = const T &;
    using storage_type = std::array<T, D>;

    constexpr fixed_stack();
    constexpr explicit fixed_stack(const storage_type &data);

    constexpr reference operator[](const size_type index) noexcept;
    constexpr const_reference operator[](const size_type index) const noexcept;

    constexpr auto begin() noexcept;
    constexpr auto begin() const noexcept;
    constexpr auto end() noexcept;
    constexpr auto end() const noexcept;

    constexpr auto cbegin() const noexcept;
    constexpr auto cend() const noexcept;

    constexpr void push(const_reference item);
    constexpr void emplace_push();
    constexpr auto peek() const;
    constexpr auto pop();

    constexpr bool is_full() const noexcept;
    constexpr bool is_empty() const noexcept;
    constexpr auto size() const noexcept;
    constexpr auto capacity() const noexcept;
    constexpr auto data() const noexcept;

  private:
    storage_type m_data;
    size_type m_top = 0;
    const size_type m_capacity = D;
  };

  template<typename T, std::size_t D>
  constexpr fixed_stack<T, D>::fixed_stack()
  {
  }

  template<typename T, std::size_t D>
  constexpr fixed_stack<T, D>::fixed_stack(const storage_type &data)
    : m_data(data)
  {
  }

  template<typename T, std::size_t D>
  constexpr typename fixed_stack<T, D>::reference
    fixed_stack<T, D>::operator[](const size_type index) noexcept
  {
    return m_data[index];
  }

  template<typename T, std::size_t D>
  constexpr typename fixed_stack<T, D>::const_reference
    fixed_stack<T, D>::operator[](const size_type index) const noexcept
  {
    return m_data[index];
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::begin() noexcept
  {
    return m_data.begin();
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::begin() const noexcept
  {
    return m_data.begin();
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::end() noexcept
  {
    return m_data.end();
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::end() const noexcept
  {
    return m_data.end();
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::cbegin() const noexcept
  {
    return m_data.cbegin();
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::cend() const noexcept
  {
    return m_data.cend();
  }

  template<typename T, std::size_t D>
  constexpr void fixed_stack<T, D>::push(const_reference item)
  {
    /* Handle this error correctly in future. */
    if (this->is_full()) {
      atomic::detail::error("Fixed stack is full, cannot add item.");
      return;
    }

    m_data[m_top] = item;
    ++m_top;
  }

  template<typename T, std::size_t D>
  constexpr void fixed_stack<T, D>::emplace_push()
  {
    m_data[m_top] = typename fixed_stack<T, D>::type();
    ++m_top;
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::peek() const
  {
    atomic::detail::assertion(this->is_empty(), "Fixed stack is empty, cannot peek!");
    return m_data[m_top - 1];
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::pop()
  {
    atomic::detail::assertion(this->is_empty(), "Fixed stack is empty, cannot pop!");

    auto top = m_data[--m_top];
    m_data[m_top] = T();
    return top;
  }

  template<typename T, std::size_t D>
  constexpr bool fixed_stack<T, D>::is_empty() const noexcept
  {
    return (m_top == 0) ? false : true;
  }

  template<typename T, std::size_t D>
  constexpr bool fixed_stack<T, D>::is_full() const noexcept
  {
    return (m_top >= m_data.max_size()) ? true : false;
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::size() const noexcept
  {
    return m_top;
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::capacity() const noexcept
  {
    return m_capacity;
  }

  template<typename T, std::size_t D>
  constexpr auto fixed_stack<T, D>::data() const noexcept
  {
    return m_data;
  }


}// namespace container
}// namespace atomic

#endif// #define ATOMIC_CONTAINER_FIXED_STACK_HPP

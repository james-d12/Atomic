#ifndef ATOMIC_CONTAINER_DYNAMIC_STACK_HPP
#define ATOMIC_CONTAINER_DYNAMIC_STACK_HPP

#include <vector>
#include <type_traits>
#include "atomic/core/utility.hpp"

namespace atomic {
namespace container {

  template<typename T>
  class dynamic_stack
  {
    static_assert(std::is_default_constructible<T>::value, "Fixed stack type must be default constructible");

  public:
    using type = T;
    using size_type = std::size_t;
    using pointer = T *;
    using reference = T &;
    using const_reference = const T &;
    using storage_type = std::vector<T>;

    dynamic_stack();

    reference operator[](const size_type index) noexcept;
    const_reference operator[](const size_type index) const noexcept;

    auto begin() noexcept;
    auto begin() const noexcept;
    auto end() noexcept;
    auto end() const noexcept;

    void push(const_reference item);
    auto peek() const;
    auto pop();

    bool is_full() const noexcept;
    bool is_empty() const noexcept;
    auto size() const noexcept;

    void resize(const size_type size);
    void reserve(const size_type capacity);

  private:
    size_type m_top = 0;
    storage_type m_data;
  };


}// namespace container
}// namespace atomic

#endif// ATOMIC_CONTAINER_DYNAMIC_STACK_HPP
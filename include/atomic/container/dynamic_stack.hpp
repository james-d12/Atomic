#pragma once 
#ifndef ATOMIC_CONTAINER_DYNAMIC_STACK_HPP
#define ATOMIC_CONTAINER_DYNAMIC_STACK_HPP

#include <atomic/core/utility.hpp>
#include <type_traits>
#include <vector>

namespace atomic { namespace container {

template<typename T>
class dynamic_stack
{
	static_assert(std::is_default_constructible<T>::value, "Fixed stack type must be default constructible");
public:
	using type = T;
	using size_type = std::size_t;
	using pointer = T*;
	using reference = T&;
	using const_reference = const T&;
	using storage_type = std::vector<T>;

	dynamic_stack();

	const reference operator[](const size_type index) noexcept;
	const const_reference operator[](const size_type index) const noexcept;

	const auto begin() noexcept;
	const auto begin() const noexcept;
	const auto end() noexcept;
	const auto end() const noexcept;

	const void push(const_reference item);
	const auto peek() const;
	const auto pop();

	const bool is_full() const noexcept;
	const bool is_empty() const noexcept;
	const auto size() const noexcept;

	void resize(const size_type size);
	void reserve(const size_type capacity);

private:
	size_type m_top = 0;
	storage_type m_data;
};



}} // atomic::container namespace

#endif // ATOMIC_CONTAINER_DYNAMIC_STACK_HPP
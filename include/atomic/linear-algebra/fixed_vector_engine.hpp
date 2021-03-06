#pragma once
#ifndef ATOMIC_LINEAR_ALGEBRA_FIXED_VECTOR_ENGINE_HPP
#define ATOMIC_LINEAR_ALGEBRA_FIXED_VECTOR_ENGINE_HPP

#include <atomic/linear-algebra/traits.hpp>
#include <array>

namespace atomic { namespace linalg {

template<typename T, std::size_t D>
class fixed_vector_engine
{
	static_assert(is_scalar_element<T>::value, "fixed_vector_engine template parameter must be a scalar type!");
	static_assert(D > 0, "Dimension size must be greater than 0!");

/* Problematic at the moment
#if defined ATOMIC_ENABLE_DEBUG_MODE
	static_assert(D > 10000, "Fixed_vector_engine should not be used to store more than 10,000 elements, use dynamic_vector_engine instead!");
#endif 
*/

public:
	using type = T;
	using pointer = type*;
	using reference = type&;
	using const_reference = const type&;
	using size_type = std::size_t;
	using storage_type = std::array<type, D>;
	using engine_type = fixed_vector_engine_type;

	using iterator = typename storage_type::iterator;
	using const_iterator = typename storage_type::const_iterator;
	using reverse_iterator = typename storage_type::reverse_iterator;
	using const_reverse_iterator = typename storage_type::const_reverse_iterator;

	constexpr fixed_vector_engine(const fixed_vector_engine&) = default;
	constexpr fixed_vector_engine& operator=(const fixed_vector_engine&) = default;
	constexpr fixed_vector_engine(fixed_vector_engine&&) noexcept = default;
	constexpr fixed_vector_engine& operator=(fixed_vector_engine&&) noexcept = default;
	~fixed_vector_engine() noexcept = default;

	constexpr fixed_vector_engine();
	constexpr explicit fixed_vector_engine(const storage_type data);
	constexpr fixed_vector_engine(const std::initializer_list<type> data);
	constexpr fixed_vector_engine& operator=(const storage_type data);
	constexpr fixed_vector_engine& operator=(const std::initializer_list<type> data);

	ATOMIC_NODISCARD constexpr reference operator[](const size_type index) noexcept;
	ATOMIC_NODISCARD constexpr const_reference operator[](const size_type index) const noexcept;

	constexpr auto begin() noexcept;
	constexpr auto begin() const noexcept;
	constexpr auto end() noexcept;
	constexpr auto end() const noexcept;

	constexpr auto rbegin() noexcept;
	constexpr auto rbegin() const noexcept;
	constexpr auto rend() noexcept;
	constexpr auto rend() const noexcept;

	constexpr auto cbegin() const noexcept;
	constexpr auto cend() const noexcept;
	constexpr auto crbegin() const noexcept;
	constexpr auto crend() const noexcept;

	ATOMIC_NODISCARD constexpr auto data() const noexcept;
	ATOMIC_NODISCARD constexpr auto size() const noexcept;
	ATOMIC_NODISCARD constexpr auto capacity() const noexcept;

	constexpr void fill(const_reference n);

private:
	storage_type m_data;
};

template<typename T, std::size_t D>
constexpr fixed_vector_engine<T, D>::fixed_vector_engine()
{
	m_data.fill(0);
}

template<typename T, std::size_t D>
constexpr fixed_vector_engine<T, D>::fixed_vector_engine(const storage_type data)
	: m_data(data)
{
}

template<typename T, std::size_t D>
constexpr fixed_vector_engine<T, D>::fixed_vector_engine(const std::initializer_list<type> data)
{
	std::copy(std::begin(data), std::end(data), m_data.begin());
}

template<typename T, std::size_t D>
constexpr fixed_vector_engine<T, D>&
fixed_vector_engine<T, D>::operator=(const storage_type data)
{
	m_data = data;
	return *this;
}

template<typename T, std::size_t D>
constexpr fixed_vector_engine<T, D>&
fixed_vector_engine<T, D>::operator=(const std::initializer_list<type> data)
{
	std::copy(std::begin(data), std::end(data), m_data.begin());
	return *this;
}

template<typename T, std::size_t D>
constexpr typename fixed_vector_engine<T, D>::reference
fixed_vector_engine<T, D>::operator[](const size_type index) noexcept
{
	return m_data[index];
}

template<typename T, std::size_t D>
constexpr typename fixed_vector_engine<T, D>::const_reference
fixed_vector_engine<T, D>::operator[](const size_type index) const noexcept
{
	return m_data[index];
}
template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::begin() noexcept
{
	return m_data.begin();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::begin() const noexcept
{
	return m_data.begin();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::end() noexcept
{
	return m_data.end();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::end() const noexcept
{
	return m_data.end();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::rbegin() noexcept
{
	return m_data.rbegin();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::rbegin() const noexcept
{
	return m_data.rbegin();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::rend() noexcept
{
	return m_data.rend();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::rend() const noexcept
{
	return m_data.rend();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::cbegin() const noexcept
{
	return m_data.cbegin();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::cend() const noexcept
{
	return m_data.cend();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::crbegin() const noexcept
{
	return m_data.crbegin();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::crend() const noexcept
{
	return m_data.crend();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::data() const noexcept
{
	return m_data;
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::size() const noexcept
{
	return m_data.size();
}

template<typename T, std::size_t D>
constexpr auto fixed_vector_engine<T, D>::capacity() const noexcept
{
	return m_data.max_size();
}

template<typename T, std::size_t D>
constexpr void fixed_vector_engine<T, D>::fill(const_reference n)
{
	return m_data.fill(n);
}


}} // atomic::linalg


#endif // ATOMIC_LINEAR_ALGEBRA_FIXED_VECTOR_ENGINE_HPP
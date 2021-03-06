#pragma once
#ifndef ATOMIC_MATH_LINEAR_ALGEBRA_VECTOR_HPP
#define ATOMIC_MATH_LINEAR_ALGEBRA_VECTOR_HPP

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <type_traits>

#include <atomic/linear-algebra/traits.hpp>

namespace atomic { namespace linalg {

/* beginning helpful declarations */
template<class ENG> class vector;
template<typename T, std::size_t D> using fvector = vector<fixed_vector_engine<T, D>>;
template<typename T> using fvector2 = vector<fixed_vector_engine<T, 2>>;
template<typename T> using fvector3 = vector<fixed_vector_engine<T, 3>>;
template<typename T> using fvector4 = vector<fixed_vector_engine<T, 4>>;
template<typename T> using dvector = vector<dynamic_vector_engine<T>>;

template<class ENG>
class vector
{
	static_assert(is_engine_vector<ENG>::value, "Template parameter must be a valid vector engine!");
public:
	using type = typename ENG::type;
	using size_type = typename ENG::size_type;
	using reference = typename ENG::reference;
	using const_reference = typename ENG::const_reference;
	using storage_type = typename ENG::storage_type;
	using engine_type = typename ENG::engine_type;

	using iterator = typename ENG::iterator;
	using const_iterator = typename ENG::const_iterator;
	using reverse_iterator = typename ENG::reverse_iterator;
	using const_reverse_iterator = typename ENG::const_reverse_iterator;

	constexpr vector() = default;
	constexpr vector(vector&& lhs) noexcept = default;
	constexpr vector(const vector& lhs) = default;
	constexpr vector& operator=(vector&& lhs) noexcept = default;
	constexpr vector& operator=(const vector& lhs) = default;
	~vector() noexcept = default;

	constexpr explicit vector(const storage_type data);
	constexpr vector(const std::initializer_list<type> data);
	constexpr explicit vector(const ENG& engine);
	constexpr vector& operator=(const storage_type data);
	constexpr vector& operator=(const std::initializer_list<type> data);
	constexpr vector& operator=(const ENG& engine);

	ATOMIC_NODISCARD constexpr reference operator[](const size_type index) noexcept;
	ATOMIC_NODISCARD constexpr const_reference operator[](const size_type index) const noexcept;

	ATOMIC_NODISCARD constexpr auto operator+=(const vector<ENG>& rhs);
	ATOMIC_NODISCARD constexpr auto operator+=(const type scalar);
	ATOMIC_NODISCARD constexpr auto operator-=(const vector<ENG>& rhs);
	ATOMIC_NODISCARD constexpr auto operator-=(const type scalar);
	ATOMIC_NODISCARD constexpr auto operator*=(const vector<ENG>& rhs);
	ATOMIC_NODISCARD constexpr auto operator*=(const type scalar);

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

	ATOMIC_NODISCARD constexpr auto engine() const noexcept;
	ATOMIC_NODISCARD constexpr auto data() const noexcept;
	ATOMIC_NODISCARD constexpr auto is_normalised() const noexcept;
	ATOMIC_NODISCARD constexpr auto dimensions() const noexcept;
	ATOMIC_NODISCARD constexpr auto dimensions_capacity() const noexcept;

	void fill(const_reference n) noexcept;
	void set(const vector<ENG>& v) noexcept;

	constexpr void normalise() noexcept;
	ATOMIC_NODISCARD constexpr auto length() const noexcept;
	ATOMIC_NODISCARD constexpr auto length_squared() const noexcept;
	ATOMIC_NODISCARD constexpr auto normalised() const noexcept;

	void resize(const size_type size);
	void reserve(const size_type capacity);
	void resize_and_reserve(const size_type size, const size_type capacity);
private:
	ENG m_engine;
	bool m_normalised = false;
};

template<class ENG>
constexpr vector<ENG>::vector(const storage_type data)
	: m_engine(data)
{
	atomic::detail::trace("Created vector", dimensions(), " with storage type: ", typeid(data).name());

}

template<class ENG>
constexpr vector<ENG>::vector(const std::initializer_list<type> data)
	: m_engine(data)
{
	atomic::detail::trace("Created vector", dimensions(), " with storage type: ", typeid(data).name());
}

template<class ENG>
constexpr vector<ENG>::vector(const ENG& engine)
	: m_engine(engine)
{
	atomic::detail::trace("Created vector", dimensions(), " with engine_type: ", typeid(engine).name());
}

template<class ENG>
constexpr vector<ENG>&
vector<ENG>::operator=(const storage_type data)
{
	atomic::detail::trace("Copied a storage_type: ", typeid(data).name(), " into the current vector", dimensions());
	m_engine = data;
	return *this;
}

template<class ENG>
constexpr vector<ENG>&
vector<ENG>::operator=(const std::initializer_list<type> data)
{
	atomic::detail::trace("Copied a storage_type: ", typeid(data).name(), " into the current vector", dimensions());
	m_engine = data;
	return *this;
}

template<class ENG>
constexpr vector<ENG>&
vector<ENG>::operator=(const ENG& engine)
{
	atomic::detail::trace("Copied an engine_type: ", typeid(engine).name(), " into the current vector", dimensions());
	m_engine = engine;
	return *this;
}

template<class ENG>
constexpr typename vector<ENG>::reference
vector<ENG>::operator[](const size_type index) noexcept
{
	return m_engine[index];
}

template<class ENG>
constexpr typename vector<ENG>::const_reference
vector<ENG>::operator[](const size_type index) const noexcept
{
	return m_engine[index];
}

template<class ENG>
constexpr auto vector<ENG>::operator+=(const vector<ENG>& rhs)
{
	*this = *this + rhs;
	return *this;
}

template<class ENG>
constexpr auto vector<ENG>::operator+=(const type scalar)
{
	*this = *this + scalar;
	return *this;
}

template<class ENG>
constexpr auto vector<ENG>::operator-=(const vector<ENG>& rhs)
{
	*this = *this - rhs;
	return *this;
}

template<class ENG>
constexpr auto vector<ENG>::operator-=(const type scalar)
{
	*this = *this - scalar;
	return *this;
}

template<class ENG>
constexpr auto vector<ENG>::operator*=(const vector<ENG>& rhs)
{
	*this = *this * rhs;
	return *this;
}

template<class ENG>
constexpr auto vector<ENG>::operator*=(const type scalar)
{
	*this = *this * scalar;
	return *this;
}

template<class ENG>
constexpr auto vector<ENG>::begin() noexcept
{
	return m_engine.begin();
}

template<class ENG>
constexpr auto vector<ENG>::begin() const noexcept
{
	return m_engine.begin();
}

template<class ENG>
constexpr auto vector<ENG>::end() noexcept
{
	return m_engine.end();
}

template<class ENG>
constexpr auto vector<ENG>::end() const noexcept
{
	return m_engine.end();
}

template<class ENG>
constexpr auto vector<ENG>::rbegin() noexcept
{
	return m_engine.rbegin();
}

template<class ENG>
constexpr auto vector<ENG>::rbegin() const noexcept
{
	return m_engine.rbegin();
}

template<class ENG>
constexpr auto vector<ENG>::rend() noexcept
{
	return m_engine.rend();
}

template<class ENG>
constexpr auto vector<ENG>::rend() const noexcept
{
	return m_engine.rend();
}

template<class ENG>
constexpr auto vector<ENG>::cbegin() const noexcept
{
	return m_engine.cbegin();
}

template<class ENG>
constexpr auto vector<ENG>::cend() const noexcept
{
	return m_engine.cend();
}

template<class ENG>
constexpr auto vector<ENG>::crbegin() const noexcept
{
	return m_engine.crbegin();
}

template<class ENG>
constexpr auto vector<ENG>::crend() const noexcept
{
	return m_engine.crend();
}

template<class ENG>
constexpr auto vector<ENG>::engine() const noexcept
{
	return m_engine;
}

template<class ENG>
constexpr auto vector<ENG>::data() const noexcept
{
	return m_engine.data();
}

template<class ENG>
constexpr auto vector<ENG>::is_normalised() const noexcept
{
	return m_normalised;
}

template<class ENG>
constexpr auto vector<ENG>::dimensions() const noexcept
{
	return m_engine.size();
}

template<class ENG>
constexpr auto vector<ENG>::dimensions_capacity() const noexcept
{
	return m_engine.capacity();
}

template<class ENG>
constexpr void vector<ENG>::normalise() noexcept
{
	if (is_normalised()) { return; }

	auto mag = length();
	
	atomic::detail::assertion(mag == 0, "Attempted a divide by zero error.");

	std::for_each(begin(), end(), [&](auto& n) { n /= mag; });
	m_normalised = true;
}

template<class ENG>
constexpr auto vector<ENG>::length() const noexcept
{
	typename vector<ENG>::type sum(0);
	std::for_each(cbegin(), cend(), [&](const auto& n) { sum += (n * n); });
	return std::sqrt(sum);
}

template<class ENG>
constexpr auto vector<ENG>::length_squared() const noexcept
{
	typename vector<ENG>::type sum(0);
	std::for_each(cbegin(), cend(), [&](const auto& n) { sum += (n * n); });
	return sum;
}

template<class ENG>
constexpr auto vector<ENG>::normalised() const noexcept
{
	auto mag = length();
	vector<ENG> vec;
	std::copy(cbegin(), cend(), vec.begin());
	vec.normalise();
	return vec;
}

template<class ENG>
void vector<ENG>::resize(const size_type size)
{
	static_assert(engine_properties<engine_type>::is_resizable == true, "Vector must be dynamic to resize!");
	m_engine.resize(size);
}

template<class ENG>
void vector<ENG>::reserve(const size_type capacity)
{
	static_assert(engine_properties<engine_type>::is_resizable == true, "Vector must be dynamic to reserve!");
	m_engine.reserve(capacity);
}

template<class ENG>
void vector<ENG>::resize_and_reserve(const size_type size, const size_type capacity)
{
	static_assert(engine_properties<engine_type>::is_resizable == true, "Vector must be dynamic to resize and reserve!");
	m_engine.resize(size);
	m_engine.reserve(capacity);
}

template<class ENG1, class ENG2>
inline auto operator+(const vector<ENG1>& lhs, const vector<ENG2>& rhs)
{
	auto result_engine = detail::vector_engine_addition(lhs.engine(),rhs.engine());
	using result_engine_type = decltype(result_engine);
	return vector<result_engine_type>(result_engine);
}

template<class ENG1, class ENG2>
inline auto operator-(const vector<ENG1>& lhs, const vector<ENG2>& rhs)
{
	auto result_engine = detail::vector_engine_subtraction(lhs.engine(),rhs.engine());
	using result_engine_type = decltype(result_engine);
	return vector<result_engine_type>(result_engine);
}

template<class ENG1, class ENG2>
inline auto operator*(const vector<ENG1>& lhs, const vector<ENG2>& rhs)
{
	auto result_engine = detail::vector_engine_multiplication(lhs.engine(),rhs.engine());
	using result_engine_type = decltype(result_engine);
	return vector<result_engine_type>(result_engine);
}

template<class ENG, typename S,
	typename = std::enable_if_t<is_scalar_element<S>::value>>
inline auto operator+(const vector<ENG>& vec, S scalar)
{
	auto data = vec.data();
	std::for_each(data.begin(), data.end(), [&](auto& n) { n += scalar; });
	return vector<ENG>(data);
}

template<class ENG, typename S,
	typename = std::enable_if_t<is_scalar_element<S>::value>>
inline auto operator-(const vector<ENG>& vec, S scalar)
{
	auto data = vec.data();
	std::for_each(data.begin(), data.end(), [&](auto& n) { n -= scalar; });
	return vector<ENG>(data);
}

template<class ENG, typename S,
	typename = std::enable_if_t<is_scalar_element<S>::value>>
inline auto operator*(const vector<ENG>& vec, S scalar)
{
	auto data = vec.data();
	std::for_each(data.begin(), data.end(), [&](auto& n) { n *= scalar; });
	return vector<ENG>(data);
}

template<class ENG1, class ENG2>
inline auto operator==(const vector<ENG1>& lhs, const vector<ENG2>& rhs)
{
	return (lhs.dimensions() != rhs.dimensions())
	? false : detail::vector_engine_equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class ENG1, class ENG2>
inline auto operator!=(const vector<ENG1>& lhs, const vector<ENG2>& rhs)
{
	return!(lhs == rhs);
}

template<class ENG1, class ENG2>
inline auto operator>(const vector<ENG1>& lhs, const vector<ENG2>& rhs)
{
	return (lhs.dimensions() != rhs.dimensions())
	? false : detail::vector_engine_less_than(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
}

template<class ENG1, class ENG2>
inline auto operator<(const vector<ENG1>& lhs, const vector<ENG2>& rhs)
{
	return(rhs > lhs);
}

template<class ENG1, class ENG2>
inline auto operator>=(const vector<ENG1>& lhs, const vector<ENG2>& rhs)
{
	return!(lhs < rhs);
}

template<class ENG1, class ENG2>
inline auto operator<=(const vector<ENG1>& lhs, const vector<ENG2>& rhs)
{
	return!(lhs > rhs);
}

}} // atomic::linalg namespace

#endif // ATOMIC_MATH_LINEAR_ALGEBRA_VECTOR_HPP
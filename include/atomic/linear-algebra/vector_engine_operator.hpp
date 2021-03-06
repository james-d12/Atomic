#pragma once 
#ifndef ATOMIC_MATH_LINEAR_ALGEBRA_VECTOR_ENGINE_OPERATOR_HPP
#define ATOMIC_MATH_LINEAR_ALGEBRA_VECTOR_ENGINE_OPERATOR_HPP

#include <algorithm>

#include <atomic/linear-algebra/fixed_vector_engine.hpp>
#include <atomic/linear-algebra/dynamic_vector_engine.hpp>

namespace atomic { namespace linalg { namespace detail {

template<class ENG1, class ENG2, class ENG3>
inline void vector_engine_addition_helper(const ENG1& lhs, const ENG2& rhs, ENG3& src)
{
	typename ENG1::size_type index = 0;
	std::for_each(lhs.begin(), lhs.end(), [&](const auto& n) { src[index] += n; index++; });
	index = 0;
	std::for_each(rhs.begin(), rhs.end(), [&](const auto& n) { src[index] += n; index++; });
}

template<class ENG1, class ENG2, class ENG3>
inline void vector_engine_multiplication_helper(const ENG1& lhs, const ENG2& rhs, ENG3& src)
{
	typename ENG1::size_type index = 0;
	std::for_each(lhs.begin(), lhs.end(), [&](const auto& n) { src[index] *= n; index++; });
	index = 0;
	std::for_each(rhs.begin(), rhs.end(), [&](const auto& n) { src[index] *= n; index++; });
}

template<class ENG1, class ENG2>
inline auto vector_engine_addition(const ENG1& lhs, const ENG2& rhs)
{
	auto src = vector_engine_promotion(lhs, rhs);
	(lhs.size() > rhs.size()) ? vector_engine_addition_helper(rhs, lhs, src) : vector_engine_addition_helper(lhs, rhs, src);
	return src;
}

template<class ENG1, class ENG2>
inline auto vector_engine_subtraction(const ENG1& lhs, const ENG2& rhs)
{
	auto src = vector_engine_promotion(lhs, rhs);
	std::copy(lhs.cbegin(), lhs.cend(), src.begin());
	typename ENG1::size_type index = 0;
	std::for_each(rhs.begin(), rhs.end(), [&](const auto& n) { src[index] -= n; index++; });
	return src;
}

template<class ENG1, class ENG2>
inline auto vector_engine_multiplication(const ENG1& lhs, const ENG2& rhs)
{
	auto src = vector_engine_promotion(lhs, rhs);
	src.fill(1);
	(lhs.size() > rhs.size()) ? vector_engine_multiplication_helper(rhs, lhs, src) : vector_engine_multiplication_helper(lhs, rhs, src);
	return src;
}

template <class FwdIt1, class FwdIt2>
auto vector_engine_equal(FwdIt1 first1, FwdIt1 last1, FwdIt2 first2, FwdIt2 last2) noexcept
{
	unsigned int count = 0;
	while (first1 != last1)
	{
		if (first2 == last2 || !atomic::detail::are_same(*first1, *first2)) { count++; }
		++first1; ++first2;
	}
	return count <= 0;
}

template <class FwdIt1, class FwdIt2>
auto vector_engine_less_than(FwdIt1 first1, FwdIt1 last1, FwdIt2 first2, FwdIt2 last2) noexcept
{
	unsigned int count = 0;
	while (first1 != last1)
	{
		if (first2 == last2 || (*first1 >= *first2)) { count++; }
		++first1; ++first2;
	}
	return count <= 0;
}

}}} // atomic::linalg::detail namespace

#endif // ATOMIC_MATH_LINEAR_ALGEBRA_VECTOR_ENGINE_OPERATOR_HPP
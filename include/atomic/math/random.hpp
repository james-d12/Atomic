#pragma once 
#ifndef ATOMIC_MATH_RANDOM_HPP
#define ATOMIC_MATH_RANDOM_HPP

#include <random>
#include <limits>
#include <type_traits>

namespace atomic { namespace math {

template<typename IntegralType>
auto generate_number(const IntegralType min = std::numeric_limits<IntegralType>::min(), const IntegralType max = std::numeric_limits<IntegralType>::max(),
	typename std::enable_if<std::is_integral<IntegralType>::value >::type* = 0)
{
	static std::random_device rd;
	static std::mt19937 mt(rd());
	static std::uniform_int_distribution<IntegralType> dist(min, max);
	return dist(mt);
}

template<typename FloatingType>
auto generate_number(const FloatingType min = std::numeric_limits<FloatingType>::min(), const FloatingType max = std::numeric_limits<FloatingType>::max(),
	typename std::enable_if<std::is_floating_point<FloatingType>::value >::type* = 0)
{
	static std::random_device rd;
	static std::mt19937 mt(rd());
	static std::uniform_real_distribution<FloatingType> dist(min, max);
	return dist(mt);
}

}} // atomic::math namespace

#endif // ATOMIC_MATH_RANDOM_HPP
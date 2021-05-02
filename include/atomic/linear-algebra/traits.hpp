#pragma once 
#ifndef ATOMIC_LINEAR_ALGEBRA_TRAITS_HPP
#define ATOMIC_LINEAR_ALGEBRA_TRAITS_HPP

#include <complex>
#include <atomic/linear-algebra/engine_properties.hpp>
#include <atomic/linear-algebra/forwarder.hpp>

namespace atomic { namespace linalg {

template<class ENG>
struct is_engine_matrix
: public std::integral_constant<bool,engine_properties<typename ENG::engine_type>::is_matrix> {
	static_assert(std::is_class<ENG>::value, "Parameter must be a class.");
};

template<class ENG>
struct is_engine_vector
: public std::integral_constant<bool,engine_properties<typename ENG::engine_type>::is_vector> {
	static_assert(std::is_class<ENG>::value, "Parameter must be a class.");
};

template<class ENG>
struct is_engine_fixed
: public std::integral_constant<bool,engine_properties<typename ENG::engine_type>::is_fixed> {
	static_assert(std::is_class<ENG>::value, "Parameter must be a class.");
};

template<class ENG>
struct is_engine_resizable
: public std::integral_constant<bool,engine_properties<typename ENG::engine_type>::is_resizable> {
	static_assert(std::is_class<ENG>::value, "Parameter must be a class.");
};

template<typename T>
struct is_scalar_element : public std::integral_constant<bool,std::is_arithmetic<T>::value>{};
template<>
struct is_scalar_element<char> : public std::integral_constant<bool, false>{};
template<>
struct is_scalar_element<char const> : public std::integral_constant<bool, false>{};

#if defined(ATOMIC_STANDARD_17)
template<typename T> 
static constexpr bool is_engine_fixed_v = is_engine_fixed<T>::value;
template<typename T> 
static constexpr bool is_engine_resizable_v = is_engine_resizable<T>::value;
template<typename T> 
static constexpr bool is_engine_matrix_v = is_engine_matrix<T>::value;
template<typename T> 
static constexpr bool is_engine_vector_v = is_engine_vector<T>::value;
template<typename T> 
static constexpr bool is_scalar_element_v = is_scalar_element<T>::value;
#endif 

namespace detail {

template<typename T1, typename T2>
struct element_promotion_helper {
	static_assert(std::is_arithmetic<T1>::value && std::is_arithmetic<T2>::value, "Types must be arithmetic for element promotion.");
	using type = decltype(T1()* T2());
};

template<typename T1, typename T2>
using element_promotion_helper_t = typename element_promotion_helper<T1, T2>::type;

template<typename T1, typename T2>
struct element_promotion {
	using type = typename element_promotion_helper<T1, T2>::type;
};

template<typename T1, typename T2>
struct element_promotion<T1, std::complex<T2>>{
	static_assert(std::is_same<T1, T2>::value, "Types must be the same for element promotion with complex type.");
	using type = std::complex<element_promotion_helper_t<T1, T2>>;
};

template<typename T1, typename T2>
struct element_promotion<std::complex<T1>, T2>{
	static_assert(std::is_same<T1, T2>::value, "Types must be the same for element promotion with complex type.");
	using type = std::complex<element_promotion_helper_t<T1, T2>>;
};

template<typename T1, typename T2>
struct element_promotion<std::complex<T1>, std::complex<T2>>{
	static_assert(std::is_same<T1, T2>::value, "Types must be the same for element promotion with complex type.");
	using type = std::complex<element_promotion_helper_t<T1, T2>>;
};

template<typename T1, typename T2>
using element_promotion_t = typename element_promotion<T1, T2>::type;

template<class ENG1, class ENG2>
struct engine_management_promotion {
	using lhs_engine_type = typename ENG1::engine_type;
	using rhs_engine_type = typename ENG2::engine_type;

};

template<typename T1, std::size_t D1, typename T2, std::size_t D2>
static auto vector_engine_promotion(const fixed_vector_engine<T1, D1>& lhs, const fixed_vector_engine<T2, D2>& rhs) 
{
	(void)lhs; (void)rhs;
	using type = element_promotion_t<T1, T2>;
	constexpr auto size = (D1 > D2) ? D1 : D2;
	fixed_vector_engine<type, size> engine;
	return engine;
}

template<typename T1, typename T2, std::size_t D1>
static auto vector_engine_promotion(const dynamic_vector_engine<T1>& lhs, const fixed_vector_engine<T2, D1>& rhs) 
{
	using type = element_promotion_t<T1, T2>;
	const auto size = atomic::detail::max(lhs.size(), rhs.size());
	dynamic_vector_engine<type> engine(size);
	return engine;
}

template<typename T1, std::size_t D1, typename T2>
static auto vector_engine_promotion(const fixed_vector_engine<T1, D1>& lhs, const dynamic_vector_engine<T2>& rhs) 
{
	using type = element_promotion_t<T1, T2>;
	const auto size = atomic::detail::max(lhs.size(), rhs.size());
	dynamic_vector_engine<type> engine(size);
	return engine;
}

template<typename T1, typename T2>
static auto vector_engine_promotion(const dynamic_vector_engine<T1>& lhs, const dynamic_vector_engine<T2>& rhs) 
{
	using type = element_promotion_t<T1, T2>;
	const auto size = atomic::detail::max(lhs.size(), rhs.size());
	dynamic_vector_engine<type> engine(size);
	return engine;
}

template<typename T1, std::size_t R1, std::size_t C1, enum MatrixOrder O, 
		 typename T2, std::size_t R2, std::size_t C2>
ATOMIC_NODISCARD static constexpr auto matrix_engine_promotion(const fixed_matrix_engine<T1, R1, C1, O>& lhs, const fixed_matrix_engine<T2, R2, C2, O>& rhs)
{
	using type = element_promotion_t<T1, T2>;
	constexpr auto rows = atomic::detail::max(R1, R2);
	constexpr auto columns = atomic::detail::max(C1, C2);
	fixed_matrix_engine<type, rows, columns, O> engine;
	return engine;
}

template<typename T1,enum MatrixOrder O, typename T2, std::size_t R, std::size_t C>
ATOMIC_NODISCARD static auto matrix_engine_promotion(const dynamic_matrix_engine<T1, O>& lhs, const fixed_matrix_engine<T2, R, C, O>& rhs)
{
	using type = element_promotion_t<T1, T2>;
	const auto rows = atomic::detail::max(lhs.rows(), rhs.rows());
	const auto columns = atomic::detail::max(lhs.columns(), rhs.columns());
	dynamic_matrix_engine<type, O> engine((rows * columns)); 
	return engine;
}

template<typename T1, std::size_t R, std::size_t C, enum MatrixOrder O, typename T2>
ATOMIC_NODISCARD static auto matrix_engine_promotion(const fixed_matrix_engine<T1, R, C, O>& lhs, const dynamic_matrix_engine<T2, O>& rhs)
{
	using type = element_promotion_t<T1, T2>;
	const auto rows = atomic::detail::max(lhs.rows(), rhs.rows());
	const auto columns = atomic::detail::max(lhs.columns(), rhs.columns());
	dynamic_matrix_engine<type, O> engine((rows * columns));
	return engine;
}

template<typename T1, enum MatrixOrder O, typename T2>
ATOMIC_NODISCARD static auto matrix_engine_promotion(const dynamic_matrix_engine<T1, O>& lhs, const dynamic_matrix_engine<T2, O>& rhs)
{
	using type = element_promotion_t<T1, T2>;
	const auto rows = atomic::detail::max(lhs.rows(), rhs.rows());
	const auto columns = atomic::detail::max(lhs.columns(), rhs.columns());
	dynamic_matrix_engine<type, O> engine((rows * columns));
	return engine; 
}

} // atomic::linalg::detail namespace

}} // atomic::linalg namespace

#endif // ATOMICLINEAR_ALGEBRA_TRAITS_HPP
#pragma once 
#ifndef ATOMIC_MATH_LINEAR_ALGEBRA_QUARTERNION_HPP
#define ATOMIC_MATH_LINEAR_ALGEBRA_QUARTERNION_HPP

#include "vector.hpp"

namespace atomic { namespace linalg {

template<typename T>
class quarternion
{
    static_assert(std::is_floating_point<T>::value, "Type must be floating point!");
public:
    using type = T;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;

    constexpr quarternion() = default;
    constexpr quarternion(quarternion&& lhs) noexcept = default;
    constexpr quarternion(const quarternion& lhs) = default;
    constexpr quarternion& operator=(quarternion&& lhs) noexcept = default;
    constexpr quarternion& operator=(const quarternion& lhs) = default;
    ~quarternion() noexcept = default;

    constexpr quarternion(const T x, const T y, const T z, const T w);
    constexpr explicit quarternion(const fvector4<T>& vec4);
    constexpr quarternion(const std::initializer_list<type> data);
    constexpr quarternion& operator=(const fvector4<T>& vec4);
    constexpr quarternion& operator=(const std::initializer_list<type> data);

    ATOMIC_NODISCARD constexpr reference operator[](const size_type index);
    ATOMIC_NODISCARD constexpr const_reference operator[](const size_type index) const;

	constexpr void set(const fvector4<T>& vec4);
    constexpr void set_rotation(const T rotation);

    ATOMIC_NODISCARD constexpr auto x() const;
    ATOMIC_NODISCARD constexpr auto y() const;
    ATOMIC_NODISCARD constexpr auto z() const;
    ATOMIC_NODISCARD constexpr auto w() const;

    ATOMIC_NODISCARD constexpr auto length() const;
    ATOMIC_NODISCARD constexpr auto length_squared() const;
    ATOMIC_NODISCARD constexpr auto vector4() const;

private:
    fvector4<T> m_vector4;
};

template<typename T>
constexpr quarternion<T>::quarternion(const T x, const T y, const T z, const T w)
    : m_vector4({x,y,z,w})
{
    atomic::detail::trace("Created a quarternion with the values: ", x, ",", y, ",", z, ",", w);
}

template<typename T>
constexpr quarternion<T>::quarternion(const fvector4<T>& vec4)
    : m_vector4(vec4)
{

}

template<typename T>
constexpr quarternion<T>::quarternion(const std::initializer_list<type> data)
    : m_vector4(data)
{

}

template<typename T>
constexpr quarternion<T>&
quarternion<T>::operator=(const fvector4<T>& vec4)
{
    m_vector4 = vec4;
    return *this;
}

template<typename T>
constexpr quarternion<T>&
quarternion<T>::operator=(const std::initializer_list<type> data)
{
    m_vector4 = data;
    return *this;
}

template<typename T>
constexpr typename quarternion<T>::reference
quarternion<T>::operator[](const size_type index)
{
    return m_vector4[index];
}

template<typename T>
constexpr typename quarternion<T>::const_reference
quarternion<T>::operator[](const size_type index) const
{
    return m_vector4[index];
}

template<typename T>
constexpr void quarternion<T>::set(const fvector4<T>& vec4)
{
    m_vector4 = vec4;
}

template<typename T>
constexpr void quarternion<T>::set_rotation(const T rotation)
{
	m_vector4[3] = rotation;
}

template<typename T>
constexpr auto quarternion<T>::x() const
{
    return m_vector4[0];
}

template<typename T>
constexpr auto quarternion<T>::y() const
{
    return m_vector4[1];
}

template<typename T>
constexpr auto quarternion<T>::z() const
{
    return m_vector4[2];
}

template<typename T>
constexpr auto quarternion<T>::w() const
{
    return m_vector4[3];
}

template<typename T>
constexpr auto quarternion<T>::length() const
{
    return std::sqrt(
        (m_vector4[0] * m_vector4[0]) +
        (m_vector4[1] * m_vector4[1]) +
        (m_vector4[2] * m_vector4[2]) +
        (m_vector4[3] * m_vector4[3])
    );
}

template<typename T>
constexpr auto quarternion<T>::length_squared() const
{
    return(
        (m_vector4[0] * m_vector4[0]) +
        (m_vector4[1] * m_vector4[1]) +
        (m_vector4[2] * m_vector4[2]) +
        (m_vector4[3] * m_vector4[3])
    );
}

template<typename T>
constexpr auto quarternion<T>::vector4() const
{
    return m_vector4;
}

template<typename T1, typename T2>
constexpr auto operator+(const quarternion<T1>& lhs, const quarternion<T2>& rhs)
{
	using type = detail::element_promotion_t<T1, T2>;
    return quarternion<type>(
        (lhs.x() + rhs.x()),
        (lhs.y() + rhs.y()),
        (lhs.z() + rhs.z()),
        (lhs.w() + rhs.w())
    );
}

template<typename T1, typename T2>
constexpr auto operator-(const quarternion<T1>& lhs, const quarternion<T2>& rhs)
{
	using type = detail::element_promotion_t<T1, T2>;
	return quarternion<type>(
		(lhs.x() - rhs.x()),
		(lhs.y() - rhs.y()),
		(lhs.z() - rhs.z()),
		(lhs.w() - rhs.w())
	);
}

template<typename T1, typename T2>
constexpr auto operator*(const quarternion<T1>& lhs, const quarternion<T2>& rhs)
{
    const auto x1 = lhs.x();
    const auto x2 = rhs.x();
    const auto y1 = lhs.y();
    const auto y2 = rhs.y();
    const auto z1 = lhs.z();
    const auto z2 = rhs.z();
    const auto w1 = lhs.w();
    const auto w2 = rhs.w();

    using type = detail::element_promotion_t<T1, T2>;
    return quarternion<type>(
        ((w1 * x2) + (x1 * w2) + (y1 * z2) - (z1 * y2)),
        ((w1 * y2) - (x1 * z2) + (y1 * w2) + (z1 * x2)),
        ((w1 * z2) + (x1 * y2) - (y1 * x2) + (z1 * w2)),
        ((w1 * w2) - (x1 * x2) - (y1 * y2) - (z1 * z2))
   );
}


}} // atomic::linalg namespace

#endif // ATOMIC_MATH_LINEAR_ALGEBRA_QUARTERNION_HPP
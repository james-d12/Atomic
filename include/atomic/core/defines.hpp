#ifndef ATOMIC_CORE_DEFINES_HPP
#define ATOMIC_CORE_DEFINES_HPP

#define ATOMIC_UNUSED(x) (void)x;

#include <atomic/core/compiler.hpp>
#include <atomic/core/operating_system.hpp>
#include <atomic/core/standard.hpp>

#if defined(ATOMIC_STANDARD_14)
#define ATOMIC_DEPRECATED [[deprecated]]
#else
#define ATOMIC_DEPRECATED
#endif

#if defined(ATOMIC_STANDARD_17)
#define ATOMIC_NODISCARD [[nodiscard]]
#define ATOMIC_MAYBE_UNUSED [[maybe_unused]]
#else
#define ATOMIC_NODISCARD
#define ATOMIC_MAYBE_UNUSED
#endif

#if defined(ATOMIC_STANDARD_17)
#define ATOMIC_CONSTEXPR17 constexpr
#else
#define ATOMIC_CONSTEXPR17 inline
#endif

#if defined(ATOMIC_STANDARD_20)
#define ATOMIC_CONSTEXPR20 constexpr
#else
#define ATOMIC_CONSTEXPR20 inline
#endif

#if defined(ATOMIC_COMPILER_MSC)
#define ATOMIC_ALWAYS_INLINE [[msvc::always_inline]]
#elif defined(ATOMIC_COMPILER_GCC) || defined(ATOMIC_COMPILER_CLANG)
#define ATOMIC_ALWAYS_INLINE [[gnu::always_inline]]
#else
#define ATOMIC_ALWAYS_INLINE
#endif

#if defined(ATOMIC_OS_WINDOWS)
#include <float.h>
static constexpr auto ATOMIC_FLT_EPSILON = FLT_EPSILON;
static constexpr auto ATOMIC_DBL_EPSILON = DBL_EPSILON;
static constexpr auto ATOMIC_LDBL_EPSILON = LDBL_EPSILON;
#else
static constexpr auto ATOMIC_FLT_EPSILON = 1.192092896e-07F;
static constexpr auto ATOMIC_DBL_EPSILON = 2.2204460492503131e-016;
static constexpr auto ATOMIC_LDBL_EPSILON = 2.2204460492503131e-016;
#endif

#endif// ATOMIC_CORE_DEFINES_HPP
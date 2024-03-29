/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#ifndef ATOMIC_CORE_STANDARD_HPP
#define ATOMIC_CORE_STANDARD_HPP

#if defined(__cplusplus)
#if (__cplusplus >= 199711L)
#define ATOMIC_STANDARD_98
#endif
#if (__cplusplus >= 201103L)
#define ATOMIC_STANDARD_11
#endif
#if (__cplusplus >= 201402L)
#define ATOMIC_STANDARD_14
#endif
#if (__cplusplus >= 201702L)
#define ATOMIC_STANDARD_17
#endif
#if (__cplusplus >= 202002L)
#define ATOMIC_STANDARD_20
#endif
#else
#error "No C++ Standard Detected!"
#endif

#endif// ATOMIC_CORE_STANDARD_HPP
/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#ifndef ATOMIC_CORE_COMPILER_HPP
#define ATOMIC_CORE_COMPILER_HPP

#if defined(__clang__)
#define ATOMIC_COMPILER_CLANG
#endif

#if defined(__GNUC__)
#define ATOMIC_COMPILER_GCC
#endif

#if defined(_MSC_VER_)
#define ATOMIC_COMPILER_MSC
#endif

#if defined(__MINGW32__)
#define ATOMIC_COMPILER_MINGW32
#endif

#if defined(__MINGW64__)
#define ATOMIC_COMPILER_MINGW64
#endif

#endif// ATOMIC_CORE_COMPILER_HPP
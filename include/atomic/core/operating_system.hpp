/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#ifndef ATOMIC_CORE_OPERATING_SYSTEM_HPP
#define ATOMIC_CORE_OPERATING_SYSTEM_HPP

#if defined(_WIN16)
#define ATOMIC_OS_WINDOWS
#define ATOMIC_OS_WIN16
#elif defined(_WIN32)
#define ATOMIC_OS_WINDOWS
#define ATOMIC_OS_WIN32
#if defined(_WIN64)
#define ATOMIC_OS_WIN64
#endif
#endif

#if defined(__linux__)
#define ATOMIC_OS_LINUX
#endif

#if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) || defined(__MACH__)
#define ATOMIC_OS_MACINTOSH
#endif


#endif// ATOMIC_CORE_OPERATING_SYSTEM_HPP
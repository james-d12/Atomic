/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#ifndef ATOMIC_CORE_LOGGING_HPP
#define ATOMIC_CORE_LOGGING_HPP

#include <iostream>
#include <atomic/core/defines.hpp>

namespace atomic {
namespace detail {

  enum class Level {
    TRACE,
    INFO,
    WARNING,
    ERROR
  };

#if defined(ATOMIC_DEBUG)

#if defined(ATOMIC_OS_WINDOWS)
  constexpr auto TERM_WHITE = "\033[1;37m";
  constexpr auto TERM_YELLOW = "\033[1;33m";
  constexpr auto TERM_RED = "\033[1;31m";
  constexpr auto TERM_GREEN = "\033[1; 32m";
  constexpr auto TERM_END = "\033[0m\n";
#elif defined(ATOMIC_OS_LINUX) || defined(ATOMIC_OS_MACINTOSH)
  constexpr auto TERM_WHITE = "\x1B[37m";
  constexpr auto TERM_YELLOW = "\x1B[33m";
  constexpr auto TERM_RED = "\x1B[31m";
  constexpr auto TERM_GREEN = "\x1B[32m";
  constexpr auto TERM_END = "\033[0m\n";
#else
  constexpr auto TERM_RED = "";
  constexpr auto TERM_GREEN = "";
  constexpr auto TERM_END = "";
#endif

  static inline const char *level_as_string(const Level   &Level)
  {
    switch (Level) {
    case Level::TRACE:
      return "[TRACE]: ";
    case Level::INFO:
      return "[INFO]: ";
    case Level::WARNING:
      return "[WARNING]: ";
    case Level::ERROR:
      return "[ERROR]: ";
    default:
      return "";
    }
  }

  template<typename T>
  static inline void log_argument(T t, std::ostream &stream = std::cout)
  {
    stream << t;
  }

  template<typename... Args>
  static inline void log(Args &&... args)
  {
    std::cout << "[LOG]: ";
    int dummy[] = { 0, ((void)log_argument(std::forward<Args>(args)), 0)... };
    (void)dummy;
    std::cout << '\n';
  }

  template<typename... Args>
  static inline void trace(Args &&... args)
  {
    std::cout << TERM_WHITE << "[TRACE]: ";
    int dummy[] = { 0, ((void)log_argument(std::forward<Args>(args)), 0)... };
    (void)dummy;
    std::cout << TERM_END;
  }

  template<typename... Args>
  static inline void info(Args &&... args)
  {
    std::cout << TERM_GREEN << "[INFO]: ";
    int dummy[] = { 0, ((void)log_argument(std::forward<Args>(args)), 0)... };
    (void)dummy;
    std::cout << TERM_END;
  }

  template<typename... Args>
  static inline void warn(Args &&... args)
  {
    std::cout << TERM_YELLOW << "[WARNING]: ";
    int dummy[] = { 0, ((void)log_argument(std::forward<Args>(args)), 0)... };
    (void)dummy;
    std::cout << TERM_END;
  }

  template<typename... Args>
  static inline void error(Args &&... args)
  {
    std::cout << TERM_RED << "[ERROR]: ";
    int dummy[] = { 0, ((void)log_argument(std::forward<Args>(args), std::cerr), 0)... };
    (void)dummy;
    std::cout << TERM_END;
  }

#else

  static inline auto level_as_string(const Level &)
  {}
  template<typename T>
  static inline void log_argument(T) {}
  template<typename... Args>
  static inline void log(Args &&...) {}
  template<typename... Args>
  static inline void trace(Args &&...) {}
  template<typename... Args>
  static inline void info(Args &&..) {}
  template<typename... Args>
  static inline void warn(Args &&..) {}
  template<typename... Args>
  static inline void error(Args &&...) {}

#endif

  static inline void assertion(bool expr, const char *msg)
  {
    if (!expr) {
      std::cout << "[ASSERTION FAILURE]: " << msg << '\n';
      exit(EXIT_FAILURE);
    }
  }


}// namespace detail
}// namespace atomic

#endif// ATOMIC_CORE_LOGGING_HPP
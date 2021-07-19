/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#ifndef ATOMIC_GEOMETRY_FORWARDER_HPP
#define ATOMIC_GEOMETRY_FORWARDER_HPP

#include <cstdlib>
#include "atomic/core/utility.hpp"

namespace atomic {
namespace geometry {

  template<typename T, std::size_t D>
  struct line;

  template<typename T, std::size_t D>
  struct ray;

  template<typename T, std::size_t D>
  struct line_segment;

  template<typename T>
  class circle;

  template<typename T>
  class triangle;

}// namespace geometry
}// namespace atomic

#endif// ATOMIC_GEOMETRY_FORWARDER_HPP
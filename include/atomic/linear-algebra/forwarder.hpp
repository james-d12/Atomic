/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#ifndef ATOMIC_LINEAR_ALGEBRA_FORWARDER_HPP
#define ATOMIC_LINEAR_ALGEBRA_FORWARDER_HPP

#include <cstdlib>
#include "atomic/core/utility.hpp"
#include "atomic/linear-algebra/matrix_order.hpp"

namespace atomic {
namespace linalg {

  template<typename T, std::size_t D>
  class fixed_vector_engine;
  template<typename T>
  class dynamic_vector_engine;
  template<typename T, std::size_t R, std::size_t C, enum MatrixOrder O>
  class fixed_matrix_engine;
  template<typename T, enum MatrixOrder O>
  class dynamic_matrix_engine;
  template<class ENG>
  class vector;
  template<class ENG>
  class matrix;

}// namespace linalg
}// namespace atomic

#endif// ATOMIC_LINEAR_ALGEBRA_FORWARDER_HPP
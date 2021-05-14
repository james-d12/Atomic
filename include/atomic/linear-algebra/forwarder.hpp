#pragma once
#ifndef ATOMIC_LINEAR_ALGEBRA_FORWARDER_H
#define ATOMIC_LINEAR_ALGEBRA_FORWARDER_H

#include <atomic/linear-algebra/matrix_order.hpp>
#include <atomic/core/utility.hpp>
#include <cstdlib>

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

#endif// ATOMIC_LINEAR_ALGEBRA_FORWARDER_H
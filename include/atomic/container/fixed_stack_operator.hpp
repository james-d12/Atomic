/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#ifndef ATOMIC_CONTAINER_FIXED_STACK_OPERATOR_HPP
#define ATOMIC_CONTAINER_FIXED_STACK_OPERATOR_HPP

#include "atomic/container/fixed_stack.hpp"

namespace atomic {
namespace container {

  template<typename T1, std::size_t D, typename T2>
  bool operator==(const fixed_stack<T1, D> &lhs, const fixed_stack<T2, D> &rhs)
  {
    return (lhs.data == rhs.data);
  }

}// namespace container
}// namespace atomic

#endif// ATOMIC_CONTAINER_FIXED_STACK_OPERATOR_HPP
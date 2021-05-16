#ifndef ATOMIC_LINEAR_ALGEBRA_ENGINE_PROPERTIES_HPP
#define ATOMIC_LINEAR_ALGEBRA_ENGINE_PROPERTIES_HPP

#include "atomic/core/utility.hpp"

namespace atomic {
namespace linalg {

  using resizable_vector_engine_type = std::integral_constant<int, 1>;
  using fixed_vector_engine_type = std::integral_constant<int, 2>;
  using resizable_matrix_engine_type = std::integral_constant<int, 3>;
  using fixed_matrix_engine_type = std::integral_constant<int, 4>;

  template<class ENG>
  struct engine_properties
  {
    static constexpr bool is_resizable = false;
    static constexpr bool is_fixed = false;
    static constexpr bool is_matrix = false;
    static constexpr bool is_vector = false;
  };

  template<>
  struct engine_properties<resizable_vector_engine_type>
  {
    static constexpr bool is_resizable = true;
    static constexpr bool is_fixed = false;
    static constexpr bool is_matrix = false;
    static constexpr bool is_vector = true;
  };

  template<>
  struct engine_properties<fixed_vector_engine_type>
  {
    static constexpr bool is_resizable = false;
    static constexpr bool is_fixed = true;
    static constexpr bool is_matrix = false;
    static constexpr bool is_vector = true;
  };

  template<>
  struct engine_properties<resizable_matrix_engine_type>
  {
    static constexpr bool is_resizable = true;
    static constexpr bool is_fixed = false;
    static constexpr bool is_matrix = true;
    static constexpr bool is_vector = false;
  };

  template<>
  struct engine_properties<fixed_matrix_engine_type>
  {
    static constexpr bool is_resizable = false;
    static constexpr bool is_fixed = true;
    static constexpr bool is_matrix = true;
    static constexpr bool is_vector = false;
  };


}// namespace linalg
}// namespace atomic


#endif// ATOMIC_LINEAR_ALGEBRA_ENGINE_PROPERTIES_HPP
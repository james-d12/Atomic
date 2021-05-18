/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#include <atomic.hpp>
#include <catch2/catch.hpp>

TEST_CASE("is_engine_fixed detects invalid types.", "[trait]")
{
  CHECK_FALSE(atomic::linalg::is_engine_fixed<atomic::linalg::dynamic_vector_engine<int>>::value);
}

TEST_CASE("is_engine_fixed detects valid types.", "[trait]")
{
  CHECK(atomic::linalg::is_engine_fixed<atomic::linalg::fixed_vector_engine<int, 3>>::value == true);
  CHECK(atomic::linalg::is_engine_fixed<atomic::linalg::fixed_matrix_engine<int, 3, 3>>::value == true);
}

TEST_CASE("is_engine_resizable detects invalid types.", "[trait]")
{
  CHECK_FALSE(atomic::linalg::is_engine_resizable<atomic::linalg::fixed_vector_engine<int, 3>>::value);
}

TEST_CASE("is_engine_resizable detects valid types.", "[trait]")
{
  CHECK(atomic::linalg::is_engine_resizable<atomic::linalg::dynamic_vector_engine<int>>::value);
}

TEST_CASE("is_engine_matrix detects invalid types.", "[trait]")
{
  CHECK_FALSE((atomic::linalg::is_engine_matrix<atomic::linalg::dynamic_vector_engine<int>>::value));
  CHECK_FALSE((atomic::linalg::is_engine_matrix<atomic::linalg::fixed_vector_engine<int, 3>>::value));
}

TEST_CASE("is_engine_matrix detects valid types.", "[trait]")
{
  CHECK((atomic::linalg::is_engine_matrix<atomic::linalg::fixed_matrix_engine<int, 3, 3>>::value));
}
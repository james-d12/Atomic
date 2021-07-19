/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#include <atomic.hpp>
#include <catch2/catch.hpp>

TEST_CASE("is_scalar_element detects invalid scalars types.", "[trait]")
{
  CHECK_FALSE(atomic::linalg::is_scalar_element<char>::value);
  CHECK_FALSE(atomic::linalg::is_scalar_element<const char>::value);
  CHECK_FALSE(atomic::linalg::is_scalar_element<std::array<int, 3>>::value);
  CHECK_FALSE(atomic::linalg::is_scalar_element<std::vector<int>>::value);
}

TEST_CASE("is_scalar_element detects valid scalars types.", "[trait]")
{
  CHECK(atomic::linalg::is_scalar_element<short>::value == true);
  CHECK(atomic::linalg::is_scalar_element<short int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<signed short>::value == true);
  CHECK(atomic::linalg::is_scalar_element<signed short int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<unsigned short>::value == true);
  CHECK(atomic::linalg::is_scalar_element<unsigned short int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<signed>::value == true);
  CHECK(atomic::linalg::is_scalar_element<signed int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<unsigned>::value == true);
  CHECK(atomic::linalg::is_scalar_element<unsigned int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<long>::value == true);
  CHECK(atomic::linalg::is_scalar_element<long int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<signed long>::value == true);
  CHECK(atomic::linalg::is_scalar_element<signed long int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<unsigned long>::value == true);
  CHECK(atomic::linalg::is_scalar_element<unsigned long int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<long long>::value == true);
  CHECK(atomic::linalg::is_scalar_element<long long int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<signed long long>::value == true);
  CHECK(atomic::linalg::is_scalar_element<signed long long int>::value == true);
  CHECK(atomic::linalg::is_scalar_element<unsigned long long>::value == true);
  CHECK(atomic::linalg::is_scalar_element<unsigned long long int>::value == true);
}
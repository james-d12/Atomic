/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("Dynamic Sized Vector Subtraction - Same Type", "[dynamic-vector][subtraction]", int, unsigned int, float, double, long double)
{
  const atomic::linalg::dvector<TestType> v1 = { 1, 2, 3 };
  const atomic::linalg::dvector<TestType> v2 = { 1, 2, 3, 4 };
  const atomic::linalg::dvector<TestType> v3 = { 1, 2, 3 };
  //const atomic::linalg::dvector<TestType> v4 = { 1.1, 2.2, 3.3, 4.4 };
}

TEST_CASE("Dynamic Sized Vector Subtraction - Varying Floating", "[dynamic-vector][subtraction]")
{
}

TEST_CASE("Dynamic Sized Vector Addition - Varying", "[dynamic-vector][subtraction]")
{
}
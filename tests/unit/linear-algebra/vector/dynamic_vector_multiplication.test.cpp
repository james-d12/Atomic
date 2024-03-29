/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("Dynamic Sized Vector Multiplication - Same Type", "[dynamic-vector][multiplication][cumulative]", int, unsigned int, float, double, long double)
{
  const atomic::linalg::dvector<TestType> v1 = { 1, 2, 3 };
  const atomic::linalg::dvector<TestType> v2 = { 1, 2, 3, 4 };
  const atomic::linalg::dvector<TestType> exp = { 1, 4, 9, 4 };

  const auto res1 = v1 * v2;
  const auto res2 = v2 * v1;

  CHECK(res1 == exp);
  CHECK(typeid(res1) == typeid(exp));

  CHECK(res2 == exp);
  CHECK(typeid(res2) == typeid(exp));
}

TEST_CASE("Dynamic Sized Vector Multiplication - Varying Floating Cumulative", "[dynamic-vector][multiplication][cumulative]")
{
  const atomic::linalg::dvector<float> v1 = { 1.F, 2.F, 3.F };
  const atomic::linalg::dvector<double> v2 = { -1., -2., -3., -4. };
  const atomic::linalg::dvector<double> exp = { -1., -4., -9., -4. };

  const auto res1 = v1 * v2;
  const auto res2 = v2 * v1;

  CHECK(res1 == exp);
  CHECK(typeid(res1) == typeid(exp));

  CHECK(res2 == exp);
  CHECK(typeid(res2) == typeid(exp));
}

TEST_CASE("Dynamic Sized Vector Multiplication - Varying Cumulative", "[dynamic-vector][multiplication][cumulative]")
{
  const atomic::linalg::dvector<int> v1 = { 1, 2, 3 };
  const atomic::linalg::dvector<float> v2 = { -1.F, -2.F, -3.F, -4.F };
  const atomic::linalg::dvector<float> exp = { -1.F, -4.F, -9.F, -4.F };

  const auto res1 = v1 * v2;
  const auto res2 = v2 * v1;

  CHECK(res1 == exp);
  CHECK(typeid(res1) == typeid(exp));

  CHECK(res2 == exp);
  CHECK(typeid(res2) == typeid(exp));
}

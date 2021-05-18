#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("Fixed Sized Vector Addition - Same Type", "[fixed-vector][addition][cumulative]", int, unsigned int, float, double, long double)
{
  const atomic::linalg::fvector<TestType, 3> v1 = { 1, 2, 3 };
  const atomic::linalg::fvector<TestType, 4> v2 = { 1, 2, 3, 4 };
  const atomic::linalg::fvector<TestType, 4> exp = { 2, 4, 6, 4 };

  const auto res1 = v1 + v2;
  const auto res2 = v2 + v1;

  CHECK(res1 == exp);
  CHECK(typeid(res1) == typeid(exp));

  CHECK(res2 == exp);
  CHECK(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Addition - Varying Floating Cumulative", "[fixed-vector][addition][cumulative]")
{
  const atomic::linalg::fvector<float, 3> v1 = { 1.F, 2.F, 3.F };
  const atomic::linalg::fvector<double, 4> v2 = { 1., 2., 3., 4. };
  const atomic::linalg::fvector<double, 4> exp = { 2., 4., 6., 4. };

  const auto res1 = v1 + v2;
  const auto res2 = v2 + v1;

  CHECK(res1 == exp);
  CHECK(typeid(res1) == typeid(exp));

  CHECK(res2 == exp);
  CHECK(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Addition - Varying Cumulative", "[fixed-vector][addition][cumulative]")
{
  const atomic::linalg::fvector<int, 3> v1 = { 1, 2, 3 };
  const atomic::linalg::fvector<float, 4> v2 = { 1.1F, 2.2F, 3.3F, 4.4F };
  const atomic::linalg::fvector<float, 4> exp = { 2.1F, 4.2F, 6.3F, 4.4F };

  const auto res1 = v1 + v2;
  const auto res2 = v2 + v1;

  CHECK(res1 == exp);
  CHECK(typeid(res1) == typeid(exp));

  CHECK(res2 == exp);
  CHECK(typeid(res2) == typeid(exp));
}

#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("Quarternion Addition - Same Type", "[quarternion][addition][cumulative]", int, unsigned int, float, double, long double)
{
  /*
  const atomic::linalg::quarternion<TestType> q1 = { 1, 2, 3, 4 };
  const atomic::linalg::quarternion<TestType> q2 = { 1, 2, 3, 4 };
  const atomic::linalg::quarternion<TestType> exp = { 2, 4, 6, 4 };

  const auto res1 = q1 + q2;
  const auto res2 = q2 + q1;

  REQUIRE(res1 == exp);
  REQUIRE(typeid(res1) == typeid(exp));

  REQUIRE(res2 == exp);
  REQUIRE(typeid(res2) == typeid(exp));
  */
}
#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("element_promotion_t - same type", "[trait]", int, unsigned int, float, double, long double) 
{
  REQUIRE(typeid(atomic::linalg::detail::element_promotion_t<TestType, TestType>) == typeid(TestType));
}

TEST_CASE("element_promotion_t - varying type", "[trait]")
{
  REQUIRE(typeid(atomic::linalg::detail::element_promotion_t<float, int>) == typeid(float));
  REQUIRE(typeid(atomic::linalg::detail::element_promotion_t<float, double>) == typeid(double));
  REQUIRE(typeid(atomic::linalg::detail::element_promotion_t<signed int, int>) == typeid(int));
}

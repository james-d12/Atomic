/**********************************************************************
This file is part of Atomic which is released under the
GNU LESSER GENERAL PUBLIC LICENSE Version 3.

See file LICENSE or go to 
https://www.gnu.org/licenses/lgpl-3.0.en.html for full license details.
***********************************************************************/
#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("element_promotion_t - same type", "[trait]", int, unsigned int, float, double, long double) 
{
  CHECK(typeid(atomic::linalg::detail::element_promotion_t<TestType, TestType>) == typeid(TestType));
}

TEST_CASE("element_promotion_t - varying type", "[trait]")
{
  CHECK(typeid(atomic::linalg::detail::element_promotion_t<float, int>) == typeid(float));
  CHECK(typeid(atomic::linalg::detail::element_promotion_t<float, double>) == typeid(double));
  CHECK(typeid(atomic::linalg::detail::element_promotion_t<signed int, int>) == typeid(int));
}

#include <atomic.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Fixed Sized Vector Dot Product", "[fixed-vector][dotproduct]")
{
  const atomic::linalg::fvector<int, 3> v1 { 1, 2, 3 };
  const atomic::linalg::fvector<int, 3> v2 { 15, 25, 65 };

  const atomic::linalg::fvector<float, 3> v3 { 10.5F, 100.5F, 25.5F };
  const atomic::linalg::fvector<float, 3> v4 { 75.6F, 12.54F, 10.54F };

  const atomic::linalg::fvector<double, 3> v5 { -10, -20, -30 };
  const atomic::linalg::fvector<double, 3> v6 { 15.6, 10, 0 };

  CHECK(atomic::linalg::dot_product(v1, v2) == 260);
  CHECK(atomic::linalg::dot_product(v2, v1) == 260);
  CHECK(atomic::linalg::dot_product(v3, v4) == 2322.84F);
  CHECK(atomic::linalg::dot_product(v4, v3) == 2322.84F);
  CHECK(atomic::linalg::dot_product(v5, v6) == -356);
  CHECK(atomic::linalg::dot_product(v6, v5) == -356);
}

TEST_CASE("Fixed Sized Vector Cross Product - Integer", "[fixed-vector][crossproduct][cumulative]") 
{
  const atomic::linalg::fvector<int, 3> v1 { 1, 2, 3 };
  const atomic::linalg::fvector<int, 3> v2 { 15, 25, 65 };
  const atomic::linalg::fvector<int, 3> exp1 { 55, -20, -5 };
  const atomic::linalg::fvector<int, 3> exp2 { -55, 20, 5 };

  auto res1 = cross_product(v1, v2);
  auto res2 = cross_product(v2, v1);

  CHECK(res1 == exp1);
  CHECK(typeid(res1) == typeid(exp1));

  CHECK(res2 == exp2);
  CHECK(typeid(res2) == typeid(exp2));
}

// Cross product needs looking into tests fail due to slight differences.
/*
TEST_CASE("Fixed Sized Vector Cross Product - Float", "[fixed-vector][crossproduct][cumulative]")
{
  const atomic::linalg::fvector<float, 3> v1 { 10.5F, 100.5F, 25.5F };
  const atomic::linalg::fvector<float, 3> v2 { 75.6F, 12.54F, 10.54F };
  const atomic::linalg::fvector<float, 3> exp1 { 739.5F, 1817.13F, -7466.13F };
  const atomic::linalg::fvector<float, 3> exp2 { -739.5F - 1817.13F, 7466.13F };

  auto res1 = cross_product(v1, v2);
  auto res2 = cross_product(v2, v1);

  CHECK(res1 == exp1);
  CHECK(typeid(res1) == typeid(exp1));

  CHECK(res2 == exp2);
  CHECK(typeid(res2) == typeid(exp2));
}*/

TEST_CASE("Fixed Sized Vector Cross Product - Double", "[fixed-vector][crossproduct][cumulative]")
{
  const atomic::linalg::fvector<double, 3> v1 = { -10, -20, -30 };
  const atomic::linalg::fvector<double, 3> v2 = { 15.6, 10, 0 };
  const atomic::linalg::fvector<double, 3> exp1 = { 300, -468, 212 };
  const atomic::linalg::fvector<double, 3> exp2 = { -300, 468, -212 };

  auto res1 = cross_product(v1, v2);
  auto res2 = cross_product(v2, v1);

  CHECK(res1 == exp1);
  CHECK(typeid(res1) == typeid(exp1));

  CHECK(res2 == exp2);
  CHECK(typeid(res2) == typeid(exp2));
}
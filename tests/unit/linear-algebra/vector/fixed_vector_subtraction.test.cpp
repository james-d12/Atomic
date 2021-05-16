#include <atomic.hpp>
#include <catch2/catch.hpp>

/* Doesnt work at the moment.
TEMPLATE_TEST_CASE("Fixed Sized Vector Subtraction - Same Type", "[fixed-vector][subtraction][non-cumulative]", int, unsigned int, float, double, long double) {
    const atomic::linalg::fvector<TestType, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<TestType, 4> v2 = { 1,2,3,4 };
    const atomic::linalg::fvector<TestType, 4> exp1 = { 0,0,0,-4 };
    const atomic::linalg::fvector<TestType, 4> exp2 = { 0,0,0,4 };

    const auto res1 = v1 - v2;
    const auto res2 = v2 - v1;

    REQUIRE(res1 == exp1);
    REQUIRE(typeid(res1) == typeid(exp1));

    REQUIRE(res2 == exp2);
    REQUIRE(typeid(res2) == typeid(exp2));
}*/

TEST_CASE("Fixed Sized Vector Subtraction - Varying Floating", "[fixed-vector][subtraction][non-cumulative]") {
    const atomic::linalg::fvector<float, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<double, 4> v2 = { 1,2,3,4 };
    const atomic::linalg::fvector<double, 4> exp1 = { 0,0,0,-4 };
    const atomic::linalg::fvector<double, 4> exp2 = { 0,0,0,4 };

    const auto res1 = v1 - v2;
    const auto res2 = v2 - v1;

    REQUIRE(res1 == exp1);
    REQUIRE(typeid(res1) == typeid(exp1));

    REQUIRE(res2 == exp2);
    REQUIRE(typeid(res2) == typeid(exp2));
}

TEST_CASE("Fixed Sized Vector Subtraction - Varying", "[fixed-vector][subtraction][non-cumulative]") {
    const atomic::linalg::fvector<int, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<float, 4> v2 = { 1,2,3,4 };
    const atomic::linalg::fvector<float, 4> exp1 = { 0,0,0,-4 };
    const atomic::linalg::fvector<float, 4> exp2 = { 0,0,0,4 };

    const auto res1 = v1 - v2;
    const auto res2 = v2 - v1;

    REQUIRE(res1 == exp1);
    REQUIRE(typeid(res1) == typeid(exp1));

    REQUIRE(res2 == exp2);
    REQUIRE(typeid(res2) == typeid(exp2));
}
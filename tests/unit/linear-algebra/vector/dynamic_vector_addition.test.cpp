#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("Dynamic Sized Vector Addition - Same Type", "[dynamic-vector][addition][cumulative]", int, unsigned int, float, double, long double) {
    const atomic::linalg::dvector<TestType> v1 = { 1,2,3 };
    const atomic::linalg::dvector<TestType> v2 = { 1,2,3,4 };
    const atomic::linalg::dvector<TestType> exp = { 2,4,6,4 };

    const auto res1 = v1 + v2;
    const auto res2 = v2 + v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Dynamic Sized Vector Addition - Varying Floating Cumulative", "[dynamic-vector][addition][cumulative]") {
    const atomic::linalg::dvector<float> v1 = { 1.F,2.F,3.F };
    const atomic::linalg::dvector<double> v2 = { 1.,2.,3.,4. };
    const atomic::linalg::dvector<double> exp = { 2.,4.,6.,4. };

    const auto res1 = v1 + v2;
    const auto res2 = v2 + v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Dynamic Sized Vector Addition - Varying Cumulative", "[dynamic-vector][addition][cumulative]") {
    const atomic::linalg::dvector<int> v1 = { 1,2,3 };
    const atomic::linalg::dvector<float> v2 = { 1.1F, 2.2F, 3.3F, 4.4F };
    const atomic::linalg::dvector<float> exp = { 2.1F, 4.2F, 6.3F, 4.4F };

    const auto res1 = v1 + v2;
    const auto res2 = v2 + v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

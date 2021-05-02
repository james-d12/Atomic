#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("Dynamic Sized Vector Multiplication - Same Type", "[dynamic-vector][multiplication][cumulative]", int, unsigned int, float, double, long double) {
    const atomic::linalg::dvector<TestType> v1 = { 1,2,3 };
    const atomic::linalg::dvector<TestType> v2 = { 1,2,3,4 };
    const atomic::linalg::dvector<TestType> exp = { 1,4,9,4 };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Dynamic Sized Vector Multiplication - Varying Floating Cumulative", "[dynamic-vector][multiplication][cumulative]") {
    const atomic::linalg::dvector<float> v1 = { 1.f,2.f,3.f };
    const atomic::linalg::dvector<double> v2 = { -1.,-2.,-3.,-4. };
    const atomic::linalg::dvector<double> exp = { -1., -4., -9., -4. };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Dynamic Sized Vector Multiplication - Varying Cumulative", "[dynamic-vector][multiplication][cumulative]") {
    const atomic::linalg::dvector<int> v1 = { 1,2,3 };
    const atomic::linalg::dvector<float> v2 = { -1.f,-2.f,-3.f,-4.f };
    const atomic::linalg::dvector<float> exp = { -1.f, -4.f, -9.f, -4.f };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

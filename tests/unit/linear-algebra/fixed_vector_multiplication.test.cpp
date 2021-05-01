#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("Fixed Sized Vector Multiplication - Same Type", "[fixed-vector][multiplication][cumulative]", int, unsigned int, float, double, long double) {
    const atomic::linalg::fvector<TestType, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<TestType, 4> v2 = { 1,2,3,4 };
    const atomic::linalg::fvector<TestType, 4> exp = { 1,4,9,4 };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Multiplication - Varying Floating Cumulative", "[fixed-vector][multiplication][cumulative]") {
    const atomic::linalg::fvector<float, 3> v1 = { 1.f,2.f,3.f };
    const atomic::linalg::fvector<double, 4> v2 = { -1.,-2.,-3.,-4. };
    const atomic::linalg::fvector<double, 4> exp = { -1., -4., -9., -4. };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1; 

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Multiplication - Varying Cumulative", "[fixed-vector][multiplication][cumulative]") {
    const atomic::linalg::fvector<int, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<float, 4> v2 = { -1.f,-2.f,-3.f,-4.f };
    const atomic::linalg::fvector<float, 4> exp = { -1.f, -4.f, -9.f, -4.f };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

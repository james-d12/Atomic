#include <atomic.hpp>
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE("Fixed Sized Vector Multiplication - Same Type", "[fixed-vector][multiplication][cumulative]", int, unsigned int, float, double, long double) {
    const atomic::linalg::fvector<TestType, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<TestType, 4> v2 = { 1,2,3,4 };
    const atomic::linalg::fvector<TestType, 4> exp = { 1,4,9,4 };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1;

    CHECK(res1 == exp);
    CHECK(typeid(res1) == typeid(exp));

    CHECK(res2 == exp);
    CHECK(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Multiplication - Varying Floating Cumulative", "[fixed-vector][multiplication][cumulative]") {
    const atomic::linalg::fvector<float, 3> v1 = { 1.F,2.F,3.F };
    const atomic::linalg::fvector<double, 4> v2 = { -1.,-2.,-3.,-4. };
    const atomic::linalg::fvector<double, 4> exp = { -1., -4., -9., -4. };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1; 

    CHECK(res1 == exp);
    CHECK(typeid(res1) == typeid(exp));

    CHECK(res2 == exp);
    CHECK(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Multiplication - Varying Cumulative", "[fixed-vector][multiplication][cumulative]") {
    const atomic::linalg::fvector<int, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<float, 4> v2 = { -1.F,-2.F,-3.F,-4.F };
    const atomic::linalg::fvector<float, 4> exp = { -1.F, -4.F, -9.F, -4.F };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1;

    CHECK(res1 == exp);
    CHECK(typeid(res1) == typeid(exp));

    CHECK(res2 == exp);
    CHECK(typeid(res2) == typeid(exp));
}

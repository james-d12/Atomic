#include <atomic.hpp>
#include <catch2/catch.hpp>

/*

const fvector<int, 3> v1 = { 1,2,3 };
    const fvector<int, 4> v2 = { 1, 2, 3, 4 };
    const fvector<int, 3> v3 = { 1,2,3 };
    const fvector<float, 4> v4 = { 1.1f, 2.2f, 3.3f, 4.4f };

    const fvector<int, 4 > exp1 = { 1,4,9, 4 };
    const fvector<float, 4> exp2 = { 1.1f, 4.4f, 9.9f, 4.4f };

    EXPECT_E((v1 * v2), exp1);
    EXPECT_E((v2 * v1), exp1);
    EXPECT_E((v3 * v4), exp2);
    EXPECT_E((v4 * v3), exp2);*/

TEST_CASE("Fixed Sized Vector Multiplication - Integer Cumulative", "[fixed-vector][multiplication][cumulative]") {
    const atomic::linalg::fvector<int, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<int, 4> v2 = { 1,2,3,4 };
    const atomic::linalg::fvector<int, 4> exp = { 1,4,9,4 };

    const auto res1 = v1 * v2;
    const auto res2 = v2 * v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Multiplication - Floating Cumulative", "[fixed-vector][multiplication][cumulative]") {
    const atomic::linalg::fvector<float, 3> v1 = { 1.f,2.f,3.f };
    const atomic::linalg::fvector<float, 4> v2 = { 1.f,2,3.f,4.f };
    const atomic::linalg::fvector<float, 4> exp = { 1.f, 4.f, 9.f, 4.f };

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
    
}

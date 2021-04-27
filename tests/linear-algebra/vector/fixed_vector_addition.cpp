#include <atomic.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Fixed Sized Vector Addition - Integer Cumulative", "[fixed-vector][addition][cumulative]") {
    const atomic::linalg::fvector<int, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<int, 4> v2 = { 1,2,3,4 };
    const atomic::linalg::fvector<int, 4> exp = { 2,4,6,4 };

    const auto res1 = v1 + v2;
    const auto res2 = v2 + v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Addition - Floating Cumulative", "[fixed-vector][addition][cumulative]") {
    const atomic::linalg::fvector<float, 3> v1 = { 1.f,2.f,3.f };
    const atomic::linalg::fvector<float, 4> v2 = { 1.f,2,3.f,4.f };
    const atomic::linalg::fvector<float, 4> exp = { 2.f,4.f,6.f,4.f };

    const auto res1 = v1 + v2;
    const auto res2 = v2 + v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Addition - Varying Floating Cumulative", "[fixed-vector][addition][cumulative]") {
    const atomic::linalg::fvector<float, 3> v1 = { 1.f,2.f,3.f };
    const atomic::linalg::fvector<double, 4> v2 = { 1.,2.,3.,4. };
    const atomic::linalg::fvector<double, 4> exp = { 2.,4.,6.,4. };

    const auto res1 = v1 + v2;
    const auto res2 = v2 + v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

TEST_CASE("Fixed Sized Vector Addition - Varying Cumulative", "[fixed-vector][addition][cumulative]") {
    const atomic::linalg::fvector<int, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<float, 4> v2 = { 1.1f, 2.2f, 3.3f, 4.4f };
    const atomic::linalg::fvector<float, 4> exp = { 2.1f, 4.2f, 6.3f, 4.4f };

    const auto res1 = v1 + v2;
    const auto res2 = v2 + v1;

    REQUIRE(res1 == exp);
    REQUIRE(typeid(res1) == typeid(exp));

    REQUIRE(res2 == exp);
    REQUIRE(typeid(res2) == typeid(exp));
}

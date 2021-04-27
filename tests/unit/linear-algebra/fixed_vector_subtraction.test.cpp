#include <atomic.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Fixed Sized Vector Subtraction - Integer", "[fixed-vector][subtraction][non-cumulative]") {
    const atomic::linalg::fvector<int, 3> v1 = { 1,2,3 };
    const atomic::linalg::fvector<int, 4> v2 = { 1,2,3,4 };
    const atomic::linalg::fvector<int, 4> exp1 = { 0,0,0,-4 };
    const atomic::linalg::fvector<int, 4> exp2 = { 0,0,0,4 };

    const auto res1 = v1 - v2;
    const auto res2 = v2 - v1;

    REQUIRE(res1 == exp1);
    REQUIRE(typeid(res1) == typeid(exp1));

    REQUIRE(res2 == exp2);
    REQUIRE(typeid(res2) == typeid(exp2));
}

TEST_CASE("Fixed Sized Vector Subtraction - Floating", "[fixed-vector][subtraction][non-cumulative]") {
    const atomic::linalg::fvector<float, 3> v1 = { 1.f,2.f,3.f };
    const atomic::linalg::fvector<float, 4> v2 = { 1.f,2.f,3.f,4.f };
    const atomic::linalg::fvector<float, 4> exp1 = { 0.f, 0.f, 0.f, -4.f };
    const atomic::linalg::fvector<float, 4> exp2 = { 0.f, 0.f, 0.f, 4.f };

    const auto res1 = v1 - v2;
    const auto res2 = v2 - v1;

    REQUIRE(res1 == exp1);
    REQUIRE(typeid(res1) == typeid(exp1));

    REQUIRE(res2 == exp2);
    REQUIRE(typeid(res2) == typeid(exp2));
}

TEST_CASE("Fixed Sized Vector Subtraction - Varying Floating", "[fixed-vector][subtraction][non-cumulative]") {

}

TEST_CASE("Fixed Sized Vector Subtraction - Varying", "[fixed-vector][subtraction][non-cumulative]") {

}

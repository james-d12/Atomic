#include <atomic.hpp>
#include <catch2/catch.hpp>

TEST_CASE("is_scalar_element detects invalid scalars types.", "[trait]") {
    REQUIRE_FALSE(atomic::linalg::is_scalar_element<char>::value);
    REQUIRE_FALSE(atomic::linalg::is_scalar_element<const char>::value);
    REQUIRE_FALSE(atomic::linalg::is_scalar_element<std::array<int, 3>>::value);
    REQUIRE_FALSE(atomic::linalg::is_scalar_element<std::vector<int>>::value);
}

TEST_CASE("is_scalar_element detects valid scalars types.", "[trait]") {
    REQUIRE(atomic::linalg::is_scalar_element<short>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<short int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<signed short>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<signed short int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<unsigned short>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<unsigned short int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<signed>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<signed int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<unsigned>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<unsigned int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<long>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<long int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<signed long>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<signed long int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<unsigned long>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<unsigned long int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<long long>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<long long int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<signed long long>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<signed long long int>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<unsigned long long>::value == true);
    REQUIRE(atomic::linalg::is_scalar_element<unsigned long long int>::value == true);
}
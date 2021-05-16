#include <atomic.hpp>
#include <catch2/catch.hpp>

TEST_CASE("is_engine_fixed detects invalid types.", "[trait]") {
    REQUIRE_FALSE(atomic::linalg::is_engine_fixed<atomic::linalg::dynamic_vector_engine<int>>::value);
}

TEST_CASE("is_engine_fixed detects valid types.", "[trait]") {
    REQUIRE(atomic::linalg::is_engine_fixed<atomic::linalg::fixed_vector_engine<int, 3>>::value == true);
}

TEST_CASE("is_engine_resizable detects invalid types.", "[trait]") {
    REQUIRE_FALSE(atomic::linalg::is_engine_resizable<atomic::linalg::fixed_vector_engine<int, 3>>::value);
}

TEST_CASE("is_engine_resizable detects valid types.", "[trait]") {
    REQUIRE(atomic::linalg::is_engine_resizable<atomic::linalg::dynamic_vector_engine<int>>::value);
}

TEST_CASE("is_engine_matrix detects invalid types.", "[trait]") {
    REQUIRE_FALSE((atomic::linalg::is_engine_matrix<atomic::linalg::dynamic_vector_engine<int>>::value));
    REQUIRE_FALSE((atomic::linalg::is_engine_matrix<atomic::linalg::fixed_vector_engine<int, 3>>::value));
}

TEST_CASE("is_engine_matrix detects valid types.", "[trait]") {
    REQUIRE((atomic::linalg::is_engine_matrix<atomic::linalg::fixed_matrix_engine<int, 3, 3>>::value));
}
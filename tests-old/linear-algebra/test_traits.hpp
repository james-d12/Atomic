/*==================================================================================================
  Copyright (c) 2020 James Durban

  File:       	test_traits.hpp

  Summary:    	This is a header file that defines the functions for testing the traits aspect of the library.
  GitHub Repo: 	https://github.com/james-d12/Atom
==================================================================================================*/

#ifndef ATOM_TEST_TRAITS_HPP
#define ATOM_TEST_TRAITS_HPP

#include <test_helper.hpp>

using namespace atomic::linalg;

namespace test {

static void trait_is_scalar_element() 
{
    EXPECT_FALSE(is_scalar_element<char>::value);
	EXPECT_FALSE(is_scalar_element<const char>::value);
	EXPECT_FALSE((is_scalar_element<std::array<int,3>>::value));
	EXPECT_FALSE(is_scalar_element<std::vector<int>>::value);

    EXPECT_TRUE(is_scalar_element<short>::value);
    EXPECT_TRUE(is_scalar_element<short int>::value);
    EXPECT_TRUE(is_scalar_element<signed short>::value);
    EXPECT_TRUE(is_scalar_element<signed short int>::value);
    EXPECT_TRUE(is_scalar_element<unsigned short>::value);
    EXPECT_TRUE(is_scalar_element<unsigned short int>::value);
    EXPECT_TRUE(is_scalar_element<int>::value);
    EXPECT_TRUE(is_scalar_element<signed>::value);
    EXPECT_TRUE(is_scalar_element<signed int>::value);
    EXPECT_TRUE(is_scalar_element<unsigned>::value);
    EXPECT_TRUE(is_scalar_element<unsigned int>::value);
    EXPECT_TRUE(is_scalar_element<long>::value);
    EXPECT_TRUE(is_scalar_element<long int>::value);
    EXPECT_TRUE(is_scalar_element<signed long>::value);
    EXPECT_TRUE(is_scalar_element<signed long int>::value);
    EXPECT_TRUE(is_scalar_element<unsigned long>::value);
    EXPECT_TRUE(is_scalar_element<unsigned long int>::value);
    EXPECT_TRUE(is_scalar_element<long long>::value);
    EXPECT_TRUE(is_scalar_element<long long int>::value);
    EXPECT_TRUE(is_scalar_element<signed long long>::value);
    EXPECT_TRUE(is_scalar_element<signed long long int>::value);
    EXPECT_TRUE(is_scalar_element<unsigned long long>::value);
    EXPECT_TRUE(is_scalar_element<unsigned long long int>::value);
}

static void trait_is_engine_fixed()
{
    EXPECT_TRUE((is_engine_fixed<fixed_vector_engine<int, 3>>::value));
    EXPECT_FALSE(is_engine_fixed<dynamic_vector_engine<int>>::value);
}

static void trait_is_engine_resizable()
{
    EXPECT_TRUE(is_engine_resizable<dynamic_vector_engine<int>>::value);
    EXPECT_FALSE((is_engine_resizable<fixed_vector_engine<int, 3>>::value));
}

static void trait_is_engine_matrix()
{
    EXPECT_TRUE((is_engine_matrix<fixed_matrix_engine<int, 3, 3>>::value));
	EXPECT_FALSE((is_engine_matrix<dynamic_vector_engine<int>>::value));
	EXPECT_FALSE((is_engine_matrix<fixed_vector_engine<int, 3>>::value));
}

static void trait_is_engine_vector()
{
    EXPECT_TRUE(is_engine_vector<dynamic_vector_engine<int>>::value);
	EXPECT_TRUE((is_engine_vector<fixed_vector_engine<int, 3>>::value));
	EXPECT_FALSE((is_engine_vector<fixed_matrix_engine<int, 3, 3>>::value));
}

static void run_trait_tests()
{
    std::cout << "\n************************** TRAIT TEST RESULTS **************************" << std::endl;
	std::cout << "is_scalar_element:" << '\n';
    trait_is_scalar_element();
	std::cout << "is_engine_fixed:" << '\n';
    trait_is_engine_fixed();
	std::cout << "is_engine_resizable" << '\n';
    trait_is_engine_resizable();
	std::cout << "is_engine_matrix" << '\n';
    trait_is_engine_matrix();
	std::cout << "is_engine_vector" << '\n';
    trait_is_engine_vector();
}

}

#endif
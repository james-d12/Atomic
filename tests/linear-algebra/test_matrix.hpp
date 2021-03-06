/*==================================================================================================
  Copyright (c) 2020 James Durban

  File:       	test_matrix.hpp

  Summary:    	This is a header file that defines the functions for testing the matrix class.
  GitHub Repo: 	https://github.com/james-d12/Atom
==================================================================================================*/

#ifndef ATOM_TEST_MATRIX_HPP
#define ATOM_TEST_MATRIX_HPP

#include <test_helper.hpp>

using namespace atomic::linalg;

namespace test {

static void matrix_add_fixed_row()
{
	const fmatrix<int, 3, 3, MatrixOrder::Row> m1 = {1,2,3,4,5,6,7,8,9};
	const fmatrix<int, 3, 3, MatrixOrder::Row> m2 = {9,8,7,6,5,4,3,2,1};
	const fmatrix<int, 3, 3, MatrixOrder::Row> m3 = {1,2,3,4,5,6,7,8,9};
	const fmatrix<float, 4, 3, MatrixOrder::Row> m4 = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f, 11.11f, 12.12f };

	const fmatrix<int, 3, 3, MatrixOrder::Row> exp1 = {10,10,10,10,10,10,10,10,10};

}
static void matrix_add_fixed_col()
{

}
static void matrix_add_fixed_both();
static void matrix_sub_fixed_row();
static void matrix_sub_fixed_col();
static void matrix_sub_fixed_both();
static void matrix_mult_fixed_row();
static void matrix_mult_fixed_col();
static void matrix_mult_fixed_both();

static void matrix_add_dynamic_row();
static void matrix_add_dynamic_col();
static void matrix_add_dynamic_both();
static void matrix_sub_dynamic_row();
static void matrix_sub_dynamic_col();
static void matrix_sub_dynamic_both();
static void matrix_mult_dynamic_row();
static void matrix_mult_dynamic_col();
static void matrix_mult_dynamic_both();

static void matrix_add_both_row();
static void matrix_add_both_col();
static void matrix_add_both_both();
static void matrix_sub_both_row();
static void matrix_sub_both_col();
static void matrix_sub_both_both();
static void matrix_mult_both_row();
static void matrix_mult_both_col();
static void matrix_mult_both_both();


static void run_matrix_tests()
{
	std::cout << "\n************************** MATRIX ARITHMETIC TEST RESULTS **************************" << '\n';

	std::cout << "Fixed Matrix:" << '\n';
	matrix_add_fixed_row();
}

}

#endif
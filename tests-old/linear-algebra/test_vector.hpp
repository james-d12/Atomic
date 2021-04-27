/*==================================================================================================
  Copyright (c) 2020 James Durban

  File:       	test_vector.hpp

  Summary:    	This is a header file that defines the functions for testing the vector class.
  GitHub Repo: 	https://github.com/james-d12/Atom
==================================================================================================*/

#ifndef ATOM_TEST_VECTOR_HPP
#define ATOM_TEST_VECTOR_HPP

#include <test_helper.hpp>

using namespace atomic::linalg;

namespace test {

static void vector_add_fixed()
{
	const fvector<int, 3> v1 = {1,2,3};
	const fvector<int, 4> v2 = {1,2,3,4};
	const fvector<int, 3> v3 = {1,2,3};
	const fvector<float, 4> v4 = { 1.1f, 2.2f, 3.3f, 4.4f };

	const fvector<int, 4> exp1 = {2,4,6,4};
	const fvector<float, 4> exp2 = {2.1f, 4.2f, 6.3f, 4.4f};

	EXPECT_E((v1 + v2), exp1);
	EXPECT_E((v2 + v1), exp1);
	EXPECT_E((v3 + v4), exp2);
	EXPECT_E((v4 + v3), exp2);
}
static void vector_sub_fixed()
{
	const fvector<int, 3> v1 = { 1,2,3 };
	const fvector<int, 4> v2 = { 1, 2, 3, 4 };
	const fvector<float, 3> v3 = { 1.f,2.f,3.f };
	const fvector<double, 4> v4 = { 1.1, 2.2, 3.3, 4.4 };

	const fvector<int, 4> exp1 = {0,0,0,-4};
	const fvector<int, 4> exp2 = {0,0,0,4};
	const fvector<double, 4> exp3 = { -0.1, -0.2, -0.3, -4.4 };
	const fvector<double, 4> exp4 = { 0.1, 0.2, 0.3, 4.4 };

	EXPECT_E((v1 - v2), exp1);
	EXPECT_E((v2 - v1), exp2);
	EXPECT_E((v3 - v4), exp3);
	EXPECT_E((v4 - v3), exp4);
}
static void vector_mult_fixed()
{
	const fvector<int, 3> v1 = { 1,2,3 };
	const fvector<int, 4> v2 = { 1, 2, 3, 4 };
	const fvector<int, 3> v3 = { 1,2,3 };
	const fvector<float, 4> v4 = { 1.1f, 2.2f, 3.3f, 4.4f };

	const fvector<int, 4 > exp1 = { 1,4,9, 4 };
	const fvector<float, 4> exp2 = { 1.1f, 4.4f, 9.9f, 4.4f };

	EXPECT_E((v1 * v2), exp1);
	EXPECT_E((v2 * v1), exp1);
	EXPECT_E((v3 * v4), exp2);
	EXPECT_E((v4 * v3), exp2);
}
static void vector_add_dynamic()
{
	const dvector<int> v1 = { 1,2,3 };
	const dvector<double> v2 = { 1, 2, 3, 4 };
	const dvector<int> v3 = { 1,2,3 };
	const dvector<float> v4 = { 1.1f, 2.2f, 3.3f, 4.4f };
	const dvector<double> exp1 = { 2,4,6,4 };
	const dvector<float> exp2 = { 2.1f, 4.2f, 6.3f, 4.4f };

	EXPECT_E((v1 + v2), exp1);
	EXPECT_E((v2 + v1), exp1);
	EXPECT_E((v3 + v4), exp2);
	EXPECT_E((v4 + v3), exp2);
}
static void vector_sub_dynamic()
{
 	const dvector<int> v1 = { 1,2,3 };
	const dvector<double> v2 = { 1, 2, 3, 4 };
	const dvector<int> v3 = { 1,2,3 };
	const dvector<double> v4 = { 1.1, 2.2, 3.3, 4.4 };
	const dvector<double> exp1 = { 0.0,0.0,0.0,-4.0 };
	const dvector<double> exp2 = { 0.0,0.0,0.0, 4.0 };
	const dvector<double> exp3 = { -0.1, -0.2, -0.3, -4.4 };
	const dvector<double> exp4 = { 0.1, 0.2, 0.3, 4.4 };

	EXPECT_E((v1 - v2), exp1);
	EXPECT_E((v2 - v1), exp2);
	EXPECT_E((v3 - v4), exp3);
	EXPECT_E((v4 - v3), exp4);
}
static void vector_mult_dynamic()
{
	const dvector<int> v1 = { 1,2,3 };
	const dvector<double> v2 = { 1, 2, 3, 4 };
	const dvector<int> v3 = { 1,2,3 };
	const dvector<double> v4 = { 1.1, 2.2, 3.3, 4.4 };
	const dvector<double> exp1 = { 1.0, 4.0, 9.0, 4.0 };
	const dvector<double> exp2 = { 1.1, 4.4, 9.9, 4.4 };

	EXPECT_E((v1 * v2), exp1);
	EXPECT_E((v2 * v1), exp1);
	EXPECT_E((v3 * v4), exp2);
	EXPECT_E((v4 * v3), exp2);
}

static void vector_add_both()
{
	const dvector<int> dv1 = { 1,2,3,4,5 };
	const dvector<float> dv2 = { 10,20,30,40,50,60,70,80,90,100,110 };
	const fvector<double, 6> fv1 = { 10,9,8,7,6,5 };
	const fvector<int, 10> fv2 = { 1,2,3,4,5,6,7,8,9,10 };
	const dvector<double> exp1 = { 11,11,11,11,11,5 };
	const dvector<float> exp2 = { 11,22,33,44,55,66,77,88,99,110, 110 };

	EXPECT_E((dv1 + fv1), exp1);
	EXPECT_E((fv1 + dv1), exp1);
	EXPECT_E((dv2 + fv2), exp2);
	EXPECT_E((fv2 + dv2), exp2);
}
static void vector_sub_both()
{
	const dvector<int> dv1 = { 1,2,3,4,5 };
	const dvector<float> dv2 = { 10,20,30,40,50,60,70,80,90,100,110 };
	const fvector<double, 6> fv1 = { 10,9,8,7,6,5 };
	const fvector<int, 10> fv2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	const dvector<double> exp1 = { -9, -7, -5, -3, -1, -5 };
	const dvector<double> exp2 = { 9,  7,  5,  3,  1,  5 };
	const dvector<float> exp3 = { 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 110 };
	const dvector<float> exp4 = { -9, -18, -27, -36, -45, -54, -63, -72, -81, -90, -110 };

	EXPECT_E((dv1 - fv1), exp1);
	EXPECT_E((fv1 - dv1), exp2);
	EXPECT_E((dv2 - fv2), exp3);
	EXPECT_E((fv2 - dv2), exp4);	
}
static void vector_mult_both()
{
	const dvector<int> dv1 = { 1,2,3,4,5 };
	const dvector<float> dv2 = { 10,20,30,40,50,60,70,80,90,100,110 };
	const fvector<double, 6> fv1 = { 10,9,8,7,6,5 };
	const fvector<int, 10> fv2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	const dvector<double> exp1 = { 10, 18, 24, 28, 30, 5 };
	const dvector<float> exp2 = { 10, 40, 90, 160, 250, 360, 490, 640, 810, 1000, 110 };

	EXPECT_E((dv1 * fv1), exp1);
	EXPECT_E((fv1 * dv1), exp1);
	EXPECT_E((dv2 * fv2), exp2);
	EXPECT_E((fv2 * dv2), exp2);
}

static void vector_dot_fixed()
{
	fvector<int, 3> v1 = { 1, 2, 3};
	fvector<int, 3> v2 = { 15,25,65};

	fvector<float, 3> v3 = { 10.5f, 100.5f, 25.5f};
	fvector<float, 3> v4 = { 75.6f, 12.54f, 10.54f};

	fvector<double, 3> v5 = { -10, -20, -30 };
	fvector<double, 3> v6 = { 15.6, 10, 0};

	EXPECT_TRUE(dot_product(v1,v2) == 260);
	EXPECT_TRUE(dot_product(v2,v1) == 260);
	EXPECT_TRUE(dot_product(v3,v4) == 2322.84f);
	EXPECT_TRUE(dot_product(v4,v3) == 2322.84f);
	EXPECT_TRUE(dot_product(v5,v6) == -356);
	EXPECT_TRUE(dot_product(v6,v5) == -356);
}
static void vector_dot_dynamic()
{
	dvector<int> v1 = { 1, 2, 3};
	dvector<int> v2 = { 15,25,65};

	dvector<float> v3 = { 10.5f, 100.5f, 25.5f};
	dvector<float> v4 = { 75.6f, 12.54f, 10.54f};

	dvector<double> v5 = { -10, -20, -30 };
	dvector<double> v6 = { 15.6, 10, 0};

	EXPECT_TRUE(dot_product(v1,v2) == 260);
	EXPECT_TRUE(dot_product(v2,v1) == 260);
	EXPECT_TRUE(dot_product(v3,v4) == 2322.84f);
}
static void vector_dot_both()
{
	fvector<int, 3> v1 = { 1, 2, 3};
	dvector<int> v2 = { 15,25,65};

	fvector<float, 3> v3 = { 10.5f, 100.5f, 25.5f};
	dvector<float> v4 = { 75.6f, 12.54f, 10.54f};

	fvector<double, 3> v5 = { -10, -20, -30 };
	dvector<double> v6 = { 15.6, 10, 0};

	EXPECT_TRUE(dot_product(v1,v2) == 260);
	EXPECT_TRUE(dot_product(v2,v1) == 260);
	EXPECT_TRUE(dot_product(v3,v4) == 2322.84f);
	EXPECT_TRUE(dot_product(v4,v3) == 2322.84f);
	EXPECT_TRUE(dot_product(v5,v6) == -356);
	EXPECT_TRUE(dot_product(v6,v5) == -356);
}

static void vector_cross_fixed()
{
	fvector<int, 3> v1 = { 1, 2, 3};
	fvector<int, 3> v2 = { 15,25,65};
	fvector<int, 3> exp1 = { 55, -20, -5 };
	fvector<int, 3> exp2 = { -55, 20, 5 };

	auto res1 = cross_product(v1,v2);
	auto res2 = cross_product(v2,v1);

	fvector<float, 3> v3 = { 10.5f, 100.5f, 25.5f};
	fvector<float, 3> v4 = { 75.6f, 12.54f, 10.54f};
	fvector<float ,3> exp3 = { 739.5f, 1817.13f, -7466.13f };
	fvector<float, 3> exp4 = { -739.5f -1817.13f, 7466.13f };

	auto res3 = cross_product(v3,v4);
	auto res4 = cross_product(v4,v3);

	fvector<double, 3> v5 = { -10, -20, -30 };
	fvector<double, 3> v6 = { 15.6, 10, 0};
	fvector<double, 3> exp5 = { 300, -468, 212};
	fvector<double, 3> exp6 = { -300, 468, -212};

	auto res5 = cross_product(v5,v6);
	auto res6 = cross_product(v6,v5);

	EXPECT_TRUE(res1 == exp1 && typeid(res1).name() == typeid(exp1).name());
	EXPECT_TRUE(res2 == exp2 && typeid(res2).name() == typeid(exp2).name());
	EXPECT_TRUE(res3 == exp3 && typeid(res3).name() == typeid(exp3).name());
	EXPECT_TRUE(res4 == exp4 && typeid(res4).name() == typeid(exp4).name());
	EXPECT_TRUE(res5 == exp5 && typeid(res5).name() == typeid(exp5).name());
	EXPECT_TRUE(res6 == exp6 && typeid(res6).name() == typeid(exp6).name());
}

static void vector_cross_dynamic()
{
	dvector<int> v1 = { 1, 2, 3};
	dvector<int> v2 = { 15,25,65};
	dvector<int> exp1 = {55, -20, -5};
	dvector<int> exp2 = {-55, 20, 5};

	auto res1 = cross_product(v1,v2);
	auto res2 = cross_product(v2,v1);

	dvector<float> v3 = { 10.5f, 100.5f, 25.5f};
	dvector<float> v4 = { 75.6f, 12.54f, 10.54f};
	dvector<float> exp3 = { 739.5f, 1817.13f, -7466.13f };
	dvector<float> exp4 = { -739.5f -1817.13f, 7466.13f };

	auto res3 = cross_product(v3,v4);
	auto res4 = cross_product(v4,v3);

	dvector<double> v5 = { -10, -20, -30 };
	dvector<double> v6 = { 15.6, 10, 0};
	dvector<double> exp5 = { 300, -468, 212};
	dvector<double> exp6 = { -300, 468, -212};

	auto res5 = cross_product(v5,v6);
	auto res6 = cross_product(v6,v5);

	EXPECT_TRUE(res1 == exp1 && typeid(res1).name() == typeid(exp1).name());
	EXPECT_TRUE(res2 == exp2 && typeid(res2).name() == typeid(exp2).name());
	EXPECT_TRUE(res3 == exp3 && typeid(res3).name() == typeid(exp3).name());
	EXPECT_TRUE(res4 == exp4 && typeid(res4).name() == typeid(exp4).name());
	EXPECT_TRUE(res5 == exp5 && typeid(res5).name() == typeid(exp5).name());
	EXPECT_TRUE(res6 == exp6 && typeid(res6).name() == typeid(exp6).name());
}

static void vector_cross_both()
{
	dvector<int> v1 = { 1, 2, 3};
	fvector<int,3> v2 = { 15,25,65};
	dvector<int> exp1 = {55, -20, -5};
	dvector<int> exp2 = {-55, 20, 5};

	auto res1 = cross_product(v1,v2);
	auto res2 = cross_product(v2,v1);

	dvector<float> v3 = { 10.5f, 100.5f, 25.5f};
	fvector<float, 3> v4 = { 75.6f, 12.54f, 10.54f};
	dvector<float> exp3 = { 739.5f, 1817.13f, -7466.13f };
	dvector<float> exp4 = { -739.5f -1817.13f, 7466.13f };

	auto res3 = cross_product(v3,v4);
	auto res4 = cross_product(v4,v3);

	dvector<double> v5 = { -10, -20, -30 };
	fvector<double, 3> v6 = { 15.6, 10, 0};
	dvector<double> exp5 = { 300, -468, 212};
	dvector<double> exp6 = { -300, 468, -212};

	auto res5 = cross_product(v5,v6);
	auto res6 = cross_product(v6,v5);

	EXPECT_TRUE(res1 == exp1 && typeid(res1).name() == typeid(exp1).name());
	EXPECT_TRUE(res2 == exp2 && typeid(res2).name() == typeid(exp2).name());
	EXPECT_TRUE(res3 == exp3 && typeid(res3).name() == typeid(exp3).name());
	EXPECT_TRUE(res4 == exp4 && typeid(res4).name() == typeid(exp4).name());
	EXPECT_TRUE(res5 == exp5 && typeid(res5).name() == typeid(exp5).name());
	EXPECT_TRUE(res6 == exp6 && typeid(res6).name() == typeid(exp6).name());
}

static void run_vector_tests()
{
	std::cout << "\n************************** VECTOR ARITHMETIC TEST RESULTS **************************" << '\n';

	std::cout << "Fixed Vector:" << '\n';
	vector_add_fixed();
	vector_sub_fixed();
	vector_mult_fixed();
	vector_dot_fixed();
	vector_cross_fixed();

	std::cout << "Dynamic Vector:" << '\n';
	vector_add_dynamic();
	vector_sub_dynamic();
	vector_mult_dynamic();
	vector_dot_dynamic();
	vector_cross_dynamic();

	std::cout << "Fixed & Dynamic Vector:" << '\n';
	vector_add_both();
	vector_sub_both();
	vector_mult_both();
	vector_dot_both();
	vector_cross_both();
}

}

#endif
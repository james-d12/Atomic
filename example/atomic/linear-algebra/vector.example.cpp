#include <iostream>
#include <atomic/linear-algebra.hpp>

int main()
{
    atomic::linalg::dvector<float> v3 = { 10.5f, 100.5f, 25.5f };
	atomic::linalg::fvector<float, 3> v4 = { 75.6f, 12.54f, 10.54f };
	atomic::linalg::dvector<float> exp3 = { 739.5f, 1817.13f, -7466.13f };
	atomic::linalg::dvector<float> exp4 = { -739.5f - 1817.13f, 7466.13f };

	auto res3 = cross_product(v3, v4);
	auto res4 = cross_product(v4, v3);

    return 0;
}
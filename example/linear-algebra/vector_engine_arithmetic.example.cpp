#include <iostream>
#include <atomic/linear-algebra.hpp>

int main()
{
    atomic::linalg::fixed_vector_engine<float, 4> fve2 = { 1.25f, 2.5f, -10.f, 100.f };
	atomic::linalg::dynamic_vector_engine<int> dve1 = {1,2,4,6};

	atomic::linalg::dvector<int> v1 = {1,2,3};
	atomic::linalg::fvector3<float> v2 = {20.5, 40.5, 60.5};

	std::cout << v1.dimensions() << '\n';
	std::cout << v2.dimensions() << '\n';

	auto result = atomic::linalg::cross_product(v1,v2);

	atomic::linalg::fvector4<float> v4 = { 10.5f, 100.15f, -25.f, 12.f };
	atomic::linalg::dvector<long double> v5 = { 1000.542134234032094, -100000000000000234320439249324.0 };

	atomic::linalg::fmatrix2<int, atomic::linalg::MatrixOrder::Column> fmat2 = { 1,2,3,4};
	
	const atomic::linalg::dvector<double> v6 = { 1.1, 2.2, 3.3, 4.4 };

	fmat2.print();
    return 0;
}
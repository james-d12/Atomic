#include <iostream>
#include <atomic/linear-algebra.hpp>

int main()
{
	atomic::linalg::fmatrix2<int> fmat2 = { 1,2,3,4};
	atomic::linalg::fmatrix2<float> fmat3 = { 10.5, -15.5, -5.f, 0.f, };

	atomic::linalg::fixed_matrix_engine<int, 2, 2> fe1 = {1,2,3,4};
	atomic::linalg::fixed_matrix_engine<float, 1, 2> fe2 = { -100.f, 10.f};

	for(const auto& e : fe1){
		std::cout << " Element: " << e;
	}
	std::cout << '\n';

	atomic::linalg::fixed_vector_engine<int, 3> fve1 = {1,2,3};
	auto engine = atomic::linalg::detail::matrix_engine_promotion(fe1, fe2);

	auto res = atomic::linalg::detail::matrix_engine_multiplication(fe1, fe2);

	atomic::linalg::fmatrix2<int, atomic::linalg::MatrixOrder::Column> _fmat2 = {20, 40, 60, 80};
	atomic::linalg::fmatrix2<float, atomic::linalg::MatrixOrder::Column> _fmat3 = {10, 20 ,100, -50};

	auto res2 = _fmat2 + _fmat3;

	atomic::linalg::fvector2<int> _fvec2 = {20,40};
	atomic::linalg::fvector4<float> _fvec4 = {10,20,30,40};

	auto res3 = _fvec2 + _fvec4;
	return 0;
}
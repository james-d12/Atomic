#include <iostream>
#include <atomic/linear-algebra.hpp>

template<class T>
void print(atomic::linalg::vector<T>& vector)
{
	std::cout << "\nVector Information" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "Size: " << vector.dimensions() << std::endl;
	std::cout << "Capacity: " << vector.dimensions_capacity() << std::endl;

	std::cout << "Data: ";
	for (auto const& e : vector)
	{
		std::cout << e << ", ";
	}
	std::cout << "\n";
	std::cout << "Vector Type: " << typeid(vector).name() << std::endl;
	std::cout << "Engine Type: " << typeid(vector.engine()).name() << std::endl;
	std::cout << "Normalised:  " << ((vector.is_normalised()) ? "True" : "False") << std::endl;

	std::cout << "Length: " << vector.length() << '\n';
	std::cout << "Length Squared: " << vector.length_squared() << '\n';
	std::cout << "Alpha Direction: " << direction_cosine_alpha(vector) << '\n';
	std::cout << "Beta  Direction: " << direction_cosine_beta(vector) << '\n';
	std::cout << "Gamma Direction: " << direction_cosine_gamma(vector) << '\n';

}

int main()
{
    atomic::linalg::fvector3<int> v1 = {10, 20, 30};
    print(v1);
    return 0;
}
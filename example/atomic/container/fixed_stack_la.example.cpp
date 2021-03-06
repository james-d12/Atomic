#include <iostream>
#include <atomic/container.hpp>
#include <atomic/linear-algebra.hpp>

using namespace atomic;

int main()
{
    container::fixed_stack<linalg::fvector3<int>, 100> fs;

    fs.emplace_push();

    for(const auto& e : fs[0])
    {
        std::cout << e << '\n';
    }

    std::cout << fs.size() << '\n';
    std::cout << fs.capacity() << '\n';
}
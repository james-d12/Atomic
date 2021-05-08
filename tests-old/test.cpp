#include <linear-algebra/test_vector.hpp>
#include <linear-algebra/test_matrix.hpp>

namespace test{


struct atom_tests
{
    static void run_all_tests()
    {
        test::run_vector_tests();
        test::run_matrix_tests();
        std::cout <<  "Tests Passed: " << TERM_GREEN << pass_count << "/" << test_count << TERM_END;
        std::cout << "Tests Failed: " << TERM_RED << fail_count << "/" << test_count << TERM_END;
    }
};

}

int main()
{
    test::atom_tests::run_all_tests();
	return EXIT_SUCCESS;
}
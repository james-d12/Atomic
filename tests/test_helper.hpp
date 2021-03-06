#ifndef ATOM_TEST_HELPER_HPP
#define ATOM_TEST_HELPER_HPP

#include <iostream>
#include <atomic.hpp>

#if defined(_WIN16) || defined(_WIN32)  || defined(_WIN64)
#define TERM_RED "\033[1;31m"
#define TERM_GREEN "\033[1;32m"
#define TERM_END "\033[0m\n"
#elif defined(__linux__)
#define TERM_RED "\x1B[31m"
#define TERM_GREEN "\x1B[32m"
#define TERM_END "\033[0m\n"
#elif defined(macintosh) || defined(Macintosh) || defined(__APPLE__)
#define TERM_RED "\x1B[31m"
#define TERM_GREEN "\x1B[32m"
#define TERM_END "\033[0m\n"
#else
#define TERM_RED ""
#define TERM_GREEN ""
#define TERM_END "\n"
#endif

namespace test {

        static uint32_t fail_count = 0;
        static uint32_t pass_count = 0;
        static uint32_t test_count = 0;

        static inline void expect(bool expr, const char* file, const unsigned int line) {
            test_count++;
            if (!expr) {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
            }
            else {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
        }

        static inline void assertion(bool expr, const char* file, const unsigned int line) {
            test_count++;
            if (!expr) {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
                exit(EXIT_FAILURE);
            }
            else {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
        }

        template<typename T1, typename T2>
        static void assert_equal(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs == rhs && typeid(lhs).name() == typeid(rhs).name()) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
                exit(EXIT_FAILURE);
            }
        }

        template<typename T1, typename T2>
        static void assert_not_equal(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs != rhs && typeid(lhs).name() != typeid(rhs).name()) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
                exit(EXIT_FAILURE);
            }
        }

        template<typename T1, typename T2>
        static void assert_greater(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs > rhs) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
                exit(EXIT_FAILURE);
            }
        }

        template<typename T1, typename T2>
        static void assert_greater_equal(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs >= rhs) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
                exit(EXIT_FAILURE);
            }
        }

        template<typename T1, typename T2>
        static void assert_less(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs < rhs) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
                exit(EXIT_FAILURE);
            }
        }

        template<typename T1, typename T2>
        static void assert_less_equal(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs <= rhs) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
                exit(EXIT_FAILURE);
            }
        }

        template<typename T1, typename T2>
        static void expect_equal(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs == rhs && typeid(lhs).name() == typeid(rhs).name()) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
            }
        }

        template<typename T1, typename T2>
        static void expect_not_equal(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs != rhs && typeid(lhs).name() != typeid(rhs).name()) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
            }
        }

        template<typename T1, typename T2>
        static void expect_greater(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs > rhs) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
            }
        }

        template<typename T1, typename T2>
        static void expect_greater_equal(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs >= rhs) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
            }
        }

        template<typename T1, typename T2>
        static void expect_less(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs < rhs) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
            }
        }

        template<typename T1, typename T2>
        static void expect_less_equal(const T1& lhs, const T2& rhs, const char* file, const unsigned int line) {
            test_count++;
            if (lhs <= rhs) {
                std::cout << TERM_GREEN << "Test Pass: " << " File: " << file << " Line: " << line << TERM_END;
                pass_count++;
            }
            else {
                std::cout << TERM_RED << "Test Fail: " << " File: " << file << " Line: " << line << TERM_END;
                fail_count++;
            }
        }
}

#define EXPECT_TRUE(expr) test::expect(expr,__FILE__,__LINE__)
#define EXPECT_FALSE(expr) test::expect(!(expr),__FILE__,__LINE__)

#define ASSERT_TRUE(expr) test::assertion(expr, __FILE__, __LINE__)
#define ASSERT_FALSE(expr) test::assertion(!(expr), __FILE__, __LINE__)

#define EXPECT_E(lhs, rhs) test::expect_equal(lhs,rhs, __FILE__, __LINE__)
#define EXPECT_NE(lhs, rhs) test::expect_not_equal(lhs,rhs, __FILE__, __LINE__)
#define EXPECT_G(lhs, rhs) test::expect_greater(lhs,rhs, __FILE__, __LINE__)
#define EXPECT_GE(lhs, rhs) test::expect_greater_equal (lhs,rhs, __FILE__, __LINE__)
#define EXPECT_L(lhs, rhs) test::expect_less(lhs,rhs, __FILE__, __LINE__)
#define EXPECT_LE(lhs, rhs) test::expect_less_equal(lhs,rhs, __FILE__, __LINE__)

#define ASSERT_E(lhs, rhs) test::assert_equal(lhs, rhs, __FILE__, __LINE__)
#define ASSERT_NE(lhs, rhs) test::assert_not_equal(lhs, rhs, __FILE__, __LINE__)
#define ASSERT_G(lhs, rhs) test::assert_greater(lhs, rhs, __FILE__, __LINE__)
#define ASSERT_GE(lhs, rhs) test::assert_greater_equal(lhs, rhs, __FILE__, __LINE__)
#define ASSERT_L(lhs, rhs) test::assert_less(lhs, rhs, __FILE__, __LINE__)
#define ASSERT_LE(lhs, rhs) test::assert_less_equal(lhs, rhs, __FILE__, __LINE__)


#endif
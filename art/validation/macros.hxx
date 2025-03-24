#ifndef art__validation__macros_hxx_
#define art__validation__macros_hxx_

#include <art/validation/assert.hxx>
#include <art/validation/setup.hxx>
#include <art/validation/teardown.hxx>
#include <art/validation/test-case.hxx>

#define VALIDATION_TEST_SETUP_2(file, line)                                                \
        static void test_setup_func_##line();                                              \
        art::validation::Setup test_setup_##line(file, line, &test_setup_func_##line); \
        void test_setup_func_##line()

#define VALIDATION_TEST_SETUP_1(file, line) \
        VALIDATION_TEST_SETUP_2(file, line)

#define VALIDATION_TEST_SETUP \
        VALIDATION_TEST_SETUP_1(__FILE__, __LINE__)

#define VALIDATION_TEST_TEARDOWN_2(file, line)                                                      \
        static void test_teardown_func_##line();                                                    \
        art::validation::Teardown test_teardown_##line(file, line, &test_teardown_func_##line); \
        void test_teardown_func_##line()

#define VALIDATION_TEST_TEARDOWN_1(file, line) \
        VALIDATION_TEST_TEARDOWN_2(file, line)

#define VALIDATION_TEST_TEARDOWN \
        VALIDATION_TEST_TEARDOWN_1(__FILE__, __LINE__)

#define VALIDATION_TEST_2(name, file, line)                                                   \
        void test_func_##line();                                                              \
        art::validation::Test_case test_##line(#name, (file), (line), &test_func_##line); \
        void test_func_##line()

#define VALIDATION_TEST_1(name, file, line) \
        VALIDATION_TEST_2(name, file, line)

#define VALIDATION_TEST(name) \
        VALIDATION_TEST_1(name, __FILE__, __LINE__)

#define VALIDATION_ASSERT_TRUE(expr) \
        ::art::validation::Assert::assert_true((expr), #expr)

#define VALIDATION_ASSERT_FALSE(expr) \
        ::art::validation::Assert::assert_false((expr), #expr)

#define VALIDATION_ASSERT_NULL(expr) \
        ::art::validation::Assert::assert_null((expr), #expr)

#define VALIDATION_ASSERT_EQUAL(lhs, rhs) \
        ::art::validation::Assert::assert_equal((lhs), (rhs), #lhs, #rhs)

#define VALIDATION_ASSERT_NOT_EQUAL(lhs, rhs) \
        ::art::validation::Assert::assert_not_equal((lhs), (rhs), #lhs, #rhs)


#endif

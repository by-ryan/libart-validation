#include <art/validation/main.hxx>

VALIDATION_TEST_SETUP
{
}

VALIDATION_TEST_TEARDOWN
{
}

VALIDATION_TEST(test_true)
{
  VALIDATION_ASSERT_TRUE(true == true);
}

VALIDATION_TEST(test_false)
{
  VALIDATION_ASSERT_FALSE(true == false);
}

VALIDATION_TEST(test_null)
{
  int* ptr{nullptr};
  VALIDATION_ASSERT_NULL(ptr);
}

int
main(int argc, char* argv[])
{
  return art::validation::main(argc, argv);
}

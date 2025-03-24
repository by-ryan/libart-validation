#include <art/validation/exec.hxx>

#include <art/validation/except.hxx>
#include <art/validation/setup.hxx>
#include <art/validation/teardown.hxx>
#include <art/validation/test-case.hxx>
#include <art/validation/test-result.hxx>
#include <art/validation/utility.hxx>

namespace art::validation
{

  static
  void
  exec_setup()
  {
    auto current = Setup::first();

    if (!current) {
      return;
    }

    do {
      // fixme: report setup exceptions. fail entire unit test on exception.
      //
      current->run();
      current = current->next();
    } while (current && current != Setup::first());
  }

  static
  void
  exec_teardown()
  {
    auto current = Teardown::first();

    if (!current) {
      return;
    }

    do {
      // fixme: report teardown exceptions. fail entire unit test on exception.
      //
      current->run();
      current = current->next();
    } while (current && current != Teardown::first());
  }

  static
  bool
  exec_test_case(Test_summary& summary, Test_case& test_case)
  {
    try {
      Utility::Current<Test_case> current{&test_case};

      exec_setup();

      try {
        test_case.run();
      }
      catch (...) {
        exec_teardown();
        throw;
      }

      exec_teardown();

      summary.append({
        test_case.description(),
        test_case.file(),
        test_case.line(),
        "passed"
      });

      summary.inc_pass();

      return true;
    }
    catch (Fail const& fail) {
      summary.append({
        test_case.description(),
        test_case.file(),
        test_case.line(),
        "failed",
        fail.extras()
      });

      summary.inc_fail();
    }

    return false;
  }

  bool
  exec(Test_summary& summary)
  {
    auto current = &Test_case::first();

    if (!current) {
      return true;
    }

    bool all_passed{true};

    do {
      bool passed = exec_test_case(summary, *current);

      if (!passed) {
        all_passed = false;
      }

      current = &current->next();
    } while (current != &Test_case::first());

    return all_passed;
  }

} // namespace art::validation
